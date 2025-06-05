/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:46:15 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/05 20:25:22 by fyudris          ###   ########.fr       */
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
# ifndef BONUSB
#  define BONUSB 0
# endif

/* --- Struct Definition --- */
typedef struct s_server_state
{
	unsigned char	char_in_progress;
	int				bits_received;
	char			*message_buffer;
	size_t			message_len;
	size_t			buffer_capacity;
	pid_t			active_client_pid;
}	t_server_state;

/* --- Global Variable Declaration --- */
// The server's state, declared as 'extern' so server_utils.c
// can access it.
// The actual variable is DEFINED in server.c.
extern volatile t_server_state	g_state;

/* --- Server Utility Function Prototypes --- */
// These functions are now public to the server module
// (defined in server_utils.c)
int		init_server_state(pid_t client_pid);
int		append_char_to_buffer(unsigned char c);
#endif
