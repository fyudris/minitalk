/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:45:25 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/05 19:38:21 by fyudris          ###   ########.fr       */
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
 */
static void	client_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

/**
 * @brief (BONUS) Waits for the final acknowledgment from the server.
 */
static void	wait_for_final_ack(void)
{
	int	timeout_seconds;

	if (BONUSB)
	{
		timeout_seconds = 5;
		while (!g_ack_received && timeout_seconds > 0)
		{
			sleep(1);
			timeout_seconds--;
		}
		if (g_ack_received)
			ft_printf("Message delivered and acknowledged by server.\n");
		else
			ft_putstr_fd("Client: Timeout. No acknowledgment from server.\n",
				FD_STDERR);
	}
	else
		ft_printf("Message sent successfully.\n");
}

/**
 * @brief Sends the message string to the server character by character.
 */
static void	send_message(pid_t server_pid, const char *message)
{
	int	i;
	int	bit_index;
	int	signal_to_send;

	i = 0;
	while (1)
	{
		bit_index = 7;
		while (bit_index >= 0)
		{
			if ((message[i] >> bit_index) & 1)
				signal_to_send = SIG_BIT_ONE;
			else
				signal_to_send = SIG_BIT_ZERO;
			if (kill(server_pid, signal_to_send) == -1)
				exit(ft_putstr_fd("Error: Failed to send signal.\n", FD_STDERR));
			usleep(100);
			bit_index--;
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

/**
 * @brief Parses and validates command-line arguments.
 * Exits on failure.
 * @return pid_t The validated server PID.
 */
static pid_t	parse_and_validate_args(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
		exit(ft_printf("Usage: %s <server_pid> <message>\n", argv[0]));
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			exit(ft_printf("Error: PID must be numeric.\n"));
		i++;
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit(ft_printf("Error: Invalid PID.\n"));
	return (pid);
}

/**
 * @brief Main function for the Minitalk client.
 */
int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;

	server_pid = parse_and_validate_args(argc, argv);
	message = argv[2];
	if (BONUSB)
	{
		struct sigaction	sa_ack;

		sa_ack.sa_handler = client_ack_handler;
		sa_ack.sa_flags = SA_RESTART;
		sigemptyset(&sa_ack.sa_mask);
		sigaction(SIG_ACK, &sa_ack, NULL);
	}
	send_message(server_pid, message);
	wait_for_final_ack();
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
