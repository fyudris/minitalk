/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:45:25 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/05 17:15:40 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Global flag to indicate acknowledgment from the server (Bonus feature).
 *
 * Justification (as required by Minitalk subject):
 * For the bonus acknowledgment feature, the client must wait for a confirmation
 * signal from the server. This variable acts as the essential communication link
 * between the asynchronous signal handler (which receives the ACK) and the main
 * program flow (which waits for it). It is declared as `volatile sig_atomic_t`
 * to ensure safe access in the presence of signals. This is the single
 * permitted global variable for the client program.
 */
static volatile sig_atomic_t g_ack_received = 0;

/**
 * @brief (BONUS) Signal handler for the client to receive acknowledgment.
 *
 * This function must exist in both builds to satisfy Norminette, but it will
 * only be registered and used if BONUSB is defined as 1.
 * Its only purpose is to set the global flag when the server's ACK is received.
 *
 * @param sig The signal number received (expected to be SIG_ACK).
 */
static void client_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

/**
 * @brief Sends a single character to the server, bit by bit.
 *
 * Iterates through the 8 bits of a character (from MSB to LSB) and sends a
 * specific signal for each '1' and '0'. It includes error checking for kill.
 *
 * @param server_pid The PID of the server process.
 * @param character The character to transmit.
 */
static void send_char_as_signals(pid_t server_pid, unsigned char character)
{
	int i;
	int signal_to_send;

	i = 7;
	while (i >= 0)
	{
		if ((character >> i) & 1)
			signal_to_send = SIG_BIT_ONE;
		else
			signal_to_send = SIG_BIT_ZERO;
		if (kill(server_pid, signal_to_send) == -1)
		{
			ft_putstr_fd("Error: Failed to send signal to server PID.\n", FD_STDERR);
			exit(FAILURE);
		}
		usleep(100);
		i--;
	}
}

/**
 * @brief Checks if the given string represents a valid, positive integer PID.
 * @param pid_str The string to check.
 * @return SUCCESS (0) if valid, FAILURE (1) otherwise.
 */
static int	is_valid_pid_string(char *pid_str)
{
	int i;

	i = 0;
	if (!pid_str || pid_str[i] == '\0')
		return (FAILURE);
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Main function for the Minitalk client.
 *
 * Parses arguments, validates the server PID, sets up signal handlers (for bonus),
 * and sends the specified message to the server. For the bonus version, it waits
 * for a confirmation of receipt from the server.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return int Returns SUCCESS (0) on success, FAILURE (1) on error.
 */
int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3 || is_valid_pid_string(argv[1]) == FAILURE)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		ft_printf("Ensure <server_pid> is a positive integer.\n");
		return (FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Server PID must be a positive integer.\n", FD_STDERR);
		return (FAILURE);
	}
	message = argv[2];
	if (BONUSB)
	{
		struct sigaction	sa_ack;

		sa_ack.sa_handler = client_ack_handler;
		sa_ack.sa_flags = SA_RESTART;
		sigemptyset(&sa_ack.sa_mask);
		if (sigaction(SIG_ACK, &sa_ack, NULL) == -1)
		{
			ft_putstr_fd("Error: Client failed to set up ACK handler.\n", FD_STDERR);
			return (FAILURE);
		}
	}
	i = 0;
	while (message[i])
		send_char_as_signals(server_pid, message[i++]);
	send_char_as_signals(server_pid, '\0');
	if (BONUSB)
	{
		int	timeout_seconds;

		timeout_seconds = 5;
		while (!g_ack_received && timeout_seconds > 0)
		{
			sleep(1);
			timeout_seconds--;
		}
		if (g_ack_received)
			ft_printf("Message delivered and acknowledged by server.\n");
		else
			ft_putstr_fd("Client: Timeout. No acknowledgment from server.\n", FD_STDERR);
	}
	else
		ft_printf("Message sent successfully.\n");
	return (SUCCESS);
}

// /**
//  * @brief    Sends 8 signals to the provided PID to transmit the
//  * provided character bit by bit.
//  * It starts from the MSB and progressively goes to the LSB.
//  *
//  * It sends SIGUSR1 if the bit is 1, SIGUSR2 if it is 0.
//  *
//  * @param    pid       server's PID
//  * @param    character character to transmit
//  */
// void	send_signal(int pid, unsigned char character)
// {
// 	int				i;
// 	unsigned char	temp_char;

// 	i = 8;
// 	temp_char = character;
// 	while (i > 0)
// 	{
// 		i--;
// 		temp_char = character >> i;
// 		if (temp_char % 2 == 0)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(42);
// 	}
// }

// /**
//  * @brief    Sends a message to the server character by character.
//  *
//  * @param    argc
//  * @param    argv
//  */
// int	main(int argc, char *argv[])
// {
// 	pid_t		server_pid;
// 	const char	*message;
// 	int			i;

// 	if (argc != 3)
// 	{
// 		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
// 		exit(0);
// 	}
// 	server_pid = ft_atoi(argv[1]);
// 	message = argv[2];
// 	i = 0;
// 	while (message[i])
// 		send_signal(server_pid, message[i++]);
// 	send_signal(server_pid, '\0');
// 	return (0);
// }
