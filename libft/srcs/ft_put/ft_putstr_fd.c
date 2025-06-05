/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:07:20 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/04 15:37:41 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_putstr_fd -- write a string to a file descriptor

DESCRIPTION
    The ft_putstr_fd function writes the string `s` to the file descriptor `fd`.
    The function does nothing if the string `s` is NULL.

PARAMETERS
    s: The string to output.
    fd: The file descriptor to write to.

RETURN VALUES
    None.

NOTES
    - The function relies on `ft_putchar_fd` to write individual characters.
    - Common file descriptors:
        - 0: Standard input
        - 1: Standard output
        - 2: Standard error
*/
int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (count);
}
