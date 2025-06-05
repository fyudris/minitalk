/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:14:16 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/05 19:43:24 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Resizes the dynamic message buffer if it's full.
 * @return SUCCESS or FAILURE.
 */
static int	resize_buffer_if_needed(void)
{
	size_t	new_capacity;
	char	*resized_buffer;

	if (g_state.message_len + 1 < g_state.buffer_capacity)
		return (SUCCESS);
	if (g_state.buffer_capacity == 0)
		new_capacity = INITIAL_BUFFER_CAPACITY;
	else
		new_capacity = g_state.buffer_capacity * 2;
	resized_buffer = ft_realloc(g_state.message_buffer,
			g_state.message_len, new_capacity);
	if (!resized_buffer && new_capacity > 0)
	{
		ft_putstr_fd("Error: ft_realloc failed.\n", FD_STDERR);
		return (FAILURE);
	}
	g_state.message_buffer = resized_buffer;
	g_state.buffer_capacity = new_capacity;
	if (!g_state.message_buffer && new_capacity > 0)
		return (FAILURE);
	return (SUCCESS);
}

/**
 * @brief Initializes or resets the server's global state for message reception.
 * Frees any previously allocated message buffer, allocates a new initial buffer,
 * and resets all state variables.
 * @param client_pid The PID of the new client. If 0, general reset.
 * @return int Returns SUCCESS (0) or FAILURE (1).
 */
int	init_server_state(pid_t client_pid)
{
	if (g_state.message_buffer)
	{
		free(g_state.message_buffer);
		g_state.message_buffer = NULL;
	}
	g_state.char_in_progress = 0;
	g_state.bits_received = 0;
	g_state.message_len = 0;
	g_state.active_client_pid = client_pid;
	g_state.buffer_capacity = INITIAL_BUFFER_CAPACITY;
	g_state.message_buffer = (char *)malloc(g_state.buffer_capacity);
	if (!g_state.message_buffer)
	{
		ft_putstr_fd("Error: Server malloc failed.\n", FD_STDERR);
		g_state.buffer_capacity = 0;
		return (FAILURE);
	}
	g_state.message_buffer[0] = '\0';
	return (SUCCESS);
}

/**
 * @brief Appends a character to the dynamic message buffer.
 * @param c The character to append.
 * @return int SUCCESS or FAILURE.
 */
int	append_char_to_buffer(unsigned char c)
{
	if (!g_state.message_buffer)
	{
		if (init_server_state(g_state.active_client_pid) == FAILURE)
			return (FAILURE);
	}
	if (resize_buffer_if_needed() == FAILURE)
		return (FAILURE);
	g_state.message_buffer[g_state.message_len++] = c;
	g_state.message_buffer[g_state.message_len] = '\0';
	return (SUCCESS);
}
