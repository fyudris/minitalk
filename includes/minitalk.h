/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:46:15 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/04 16:12:08 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* --- System Includes --- */
// For sigaction, sigemptysed, sigaddset, kill, SIGUSR1, SIGUSR2
# include <signal.h>
// For write, usleep, pause, getpid, pid_t
# include <unistd.h>
// For exit, malloc, free
# include <stdlib.h>
// For size_t
# include <stddef.h>

/* --- Libft Include --- */
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

/* --- Project-Specific Definitions --- */

// Return status codes
# define FAILURE 1
# define SUCCESS 0

// Standard file descriptors
# define FD_STDOUT 1
# define FD_STDERR 2

// Signal definitions
# define SIG_BIT_ONE    SIGUSR1 // Client sends SIGUSR1 for bit '1'
# define SIG_BIT_ZERO   SIGUSR2 // Client sends SIGUSR2 for bit '0'
# define SIG_ACK        SIGUSR1 // Server sends SIGUSR1 back as ACK (for bonus)

# define INITIAL_BUFFER_CAPACITY 64

// --- Bonus Mode Definition ---
#ifndef BONUSB
# define BONUSB 0
#endif

/* --- Struct Definition --- */
// This struct is primarily for the server's internal state management.
typedef struct	s_server_state
{
	unsigned char	char_in_progress; // The byte currently being reconstructed bit by bit.
	int				bits_received; // Tract how many bits of current_char have been received (0-7)
	char			*message_buffer;
	size_t			message_len; // Current length of the string in message_buffer
	size_t			buffer_capacity; // Current allocated capacity of message_buffer
	pid_t			active_client_pid; // PID of the client whose message is being processed
}	t_server_state;



#endif
