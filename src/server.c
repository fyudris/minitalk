/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:45:38 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/04 16:16:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Global state for the server
 *
 * Justification for g_state (as required by Minitalk subject):
 * The Minitalk server communicates asynchronouly using signals.
 * Signal handlers have a restricted signature and cannot easily be passed
 * arbitrary context. To maintain the state of message reception across
 * multiple signal invocations (e.g., tracking the current client, the partially
 * built character, and the dynamically accumulating message string), a
 * persistent state accessible to the signal handler is necessary.
 *
 * A single static global struct `g_state` encapsulates all this communication
 * state.
 *
 * The `volatile` qualifier is used to ensure that the compiler does not make
 * unsafe optimizations regarding its access, as its members can be modified
 * unexpectiedly by signal handlers. Thi ensures data integrity between discrete
 * signal events and allows the server to correctly reconstruct messages bit by bit
 * from one or more clients sequentlially.
 *
 */
static volatile t_server_state	g_state;

/**
 * @brief Initializes or resets the server's global state for message reception.
 *
 * Frees any previously allocated message buffer, allocates a new initial buffer,
 * and resets all state variables.
 *
 * @param client_pid The PID of the new client. If 0, it indicates a general reset (e.g., server startup or after a message has been fully processed and acknowledged.)
 *
 * @return int Returns SUCCESS (0) if initialization is successful, FAILURE (1) if memory allocation fails.
 */
static int init_server_state(pid_t client_pid)
{
	// Free previous message buffer if it was allocated
	if (g_state.message_buffer)
	{
		free(g_state.message_buffer);
		g_state.message_buffer = NULL;
	}
	// Reset all state variables for the new message/client
	g_state.char_in_progress = 0;
	g_state.bits_received = 0;
	g_state.message_len = 0;
	g_state.active_client_pid = client_pid;
	g_state.buffer_capacity = INITIAL_BUFFER_CAPACITY;

	// Allocate memory for the new message buffer
	g_state.message_buffer = (char *)malloc(g_state.buffer_capacity);
	if (!g_state.message_buffer)
	{
		ft_putstr_fd("Error: Server failed to allocate initial mesage buffer.\n", FD_STDERR);
		g_state.buffer_capacity = 0;
		return (FAILURE);
	}
	// Ensure the newly allocated buffer starts as a valid empty string
	g_state.message_buffer[0] = '\0';
	return (SUCCESS);
}

/**
 * @brief Appends a character to the dynamic message buffer, resizing if necessary.
 *
 * Uses ft_realloc to grow the buffer.
 *
 * @param c The character to append.
 *
 * @return int SUCCESS (0) if appended, FAILURE (1) if allocation failed.
 */
static int	append_char_to_buffer(unsigned char c)
{
	size_t	new_capacity;
	char	*resized_buffer;

	if (!g_state.message_buffer)
		if (init_server_state(g_state.active_client_pid) == FAILURE)
			return (FAILURE);
	if (g_state.message_len + 1 >= g_state.buffer_capacity)
	{
		if (g_state.buffer_capacity == 0)
			new_capacity = INITIAL_BUFFER_CAPACITY;
		else
			new_capacity = g_state.buffer_capacity * 2;
		resized_buffer = ft_realloc(g_state.message_buffer, g_state.message_len, new_capacity);
		if (!resized_buffer && new_capacity > 0)
		{
			ft_putstr_fd("Error: Server ft_realloc failed. Message may be lost/truncated.\n", FD_STDERR);
			return (FAILURE);
		}
		g_state.message_buffer = resized_buffer;
		g_state.buffer_capacity = new_capacity;
		if (!g_state.message_buffer && new_capacity > 0)
			return (FAILURE);
	}
	g_state.message_buffer[g_state.message_len++] = c;
	g_state.message_buffer[g_state.message_len] = '\0';
	return (SUCCESS);
}

/**
 * @brief Main signal handler for SIGUSR1 and SIGUSR2
 *
 * Reconstructs bits to bytes, handles client differentiation, appends to buffer, prints message on '\0', and handles bonus ACK.
 *
 * @param sig The signal number received
 * @param info Pointer to siginfo_t containing sender's PID.
 * @param ucontext Unused.
 *
 */
static void	server_signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (g_state.active_client_pid == 0 || (info->si_pid != 0 && g_state.active_client_pid != info->si_pid))
	{
		if (init_server_state(info->si_pid) == FAILURE)
			return ;
	}
	if (sig == SIG_BIT_ONE)
		g_state.char_in_progress |= (1 << (7 - g_state.bits_received));
	g_state.bits_received++;
	if (g_state.bits_received == 8)
	{
		if (g_state.char_in_progress == '\0')
		{
			if (g_state.message_buffer)
				write(FD_STDOUT, g_state.message_buffer, g_state.message_len);
			write(FD_STDOUT, "\n", 1);
			if (BONUSB)
			{
				if (g_state.active_client_pid != 0)
					if (kill(g_state.active_client_pid, SIG_ACK) == -1)
						ft_putstr_fd("Server: Failed to send ACK.\n", FD_STDERR);
			}
			init_server_state(0);
		}
		else if (append_char_to_buffer(g_state.char_in_progress) == FAILURE)
		{
			ft_putstr_fd("Server: Failed to append char, message might be incomplete.\n", FD_STDERR);
			init_server_state(info->si_pid); // Reset for current client, effectively dropping current message attempt
		}
		g_state.char_in_progress = 0;
		g_state.bits_received = 0;
	}
}

/**
 * @brief Main function for the Minitalk server.
 *
 * Initializes server, prints PID, sets up signal handlers, and waits for signals.
 * @return int SUCCESS or FAILURE.
 */
int	main(void)
{
	struct sigaction	sa_config;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	if (init_server_state(0) == FAILURE)
		return (FAILURE);
	sa_config.sa_sigaction = server_signal_handler;
	sa_config.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigemptyset(&sa_config.sa_mask) == -1)
	{
		ft_putstr_fd("Error: sigemptyset failed.\n", FD_STDERR);
		if (g_state.message_buffer)
			free(g_state.message_buffer);
		return (FAILURE);
	}
	if (sigaction(SIG_BIT_ONE, &sa_config, NULL) == -1 || sigaction(SIG_BIT_ZERO, &sa_config, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction setup failed.\n", FD_STDERR);
		if (g_state.message_buffer)
			free(g_state.message_buffer);
		return (FAILURE);
	}
	ft_printf("Server ready. Waiting for signals...\n");
	while (1)
		pause();
	if (g_state.message_buffer)
		free (g_state.message_buffer);
	return (SUCCESS);
}


























// #define END_TRANSMISSION '\0'

// /**
//  * @brief    Checks if the signal is SIGUSR1. If it is, it will
//  * assign 1 to the LSB. Else, it will assign 0 (actually it simply
//  * won't modify it).
//  *
//  * Example:
//  * 00101100   current_char
//  * 00000001   result of (sigsent == SIGUSR1)
//  * --------
//  * 00101101   result stored in message after the bitwise OR operation
//  *
//  * It will then increment the bit index.
//  * If it is 8, it means that
//  * the char has been fully transmitted. It will then print it and
//  * reset the bit index and the current char.
//  * Else, it will shift the current char to the left by 1.
//  *
//  * @param    signal    SIGUSR1 or SIGUSR2
//  */
// void	handle_signal(int signal)
// {
// 	static unsigned char	current_char;
// 	static int				bit_index;

// 	current_char |= (signal == SIGUSR1);
// 	bit_index++;
// 	if (bit_index == 8)
// 	{
// 		if (current_char == END_TRANSMISSION)
// 			ft_printf("\n");
// 		else
// 			ft_printf("%c", current_char);
// 		bit_index = 0;
// 		current_char = 0;
// 	}
// 	else
// 		current_char <<= 1;
// }

// /**
//  * @brief    Prints its program's PID and calls the signal handlers.
//  */
// int	main(void)
// {
// 	printf("%d\n", getpid());
// 	signal(SIGUSR1, handle_signal);
// 	signal(SIGUSR2, handle_signal);
// 	while (1)
// 		pause();
// 	return (0);
// }
