/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:18:07 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:15:56 by fyudris          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	ft_putchar_fd(digit, fd);
}
