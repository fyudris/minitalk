/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:11:20 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:21:38 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_putendl_fd -- write a string to a file descriptor with a newline

DESCRIPTION
    The ft_putendl_fd function writes the string `s` to the file descriptor
    `fd`, followed by a newline character (`\n`). If the string `s` is NULL,
    the function does nothing.

PARAMETERS
    s: The string to output.
    fd: The file descriptor to write to.

RETURN VALUES
    None.

NOTES
    - The function relies on `ft_putstr_fd` to write the string and
      `ft_putchar_fd` to write the newline character.
    - Common file descriptors:
        - 0: Standard input
        - 1: Standard output
        - 2: Standard error
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
