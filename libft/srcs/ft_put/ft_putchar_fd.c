/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:00:45 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/05 20:25:50 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_putchar_fd -- write a character to a file descriptor

DESCRIPTION
    The ft_putchar_fd function writes the character `c` to the file descriptor
    `fd`.

PARAMETERS
    c: The character to output.
    fd: The file descriptor to write to.

RETURN VALUES
    None.

NOTES
    - If `fd` is invalid or there is an error during the `write` operation,
      the behavior is undefined.
    - Common `fd` values:
        - 0: Standard input
        - 1: Standard output
        - 2: Standard error
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
