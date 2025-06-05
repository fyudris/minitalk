/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:04:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:29 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_bzero -- write zeroes to a byte string

DESCRIPTION
    The ft_bzero function writes n zeroed bytes to the memory area pointed
    to by s. If n is zero, ft_bzero does nothing.

PARAMETERS
    s: Pointer to the memory area to be filled.
    n: Number of bytes to write as zero.
    
RETURN VALUES
    None. This function does not return a value.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*temp_ptr;

	temp_ptr = (char *) s;
	while (n > 0)
	{
		*(temp_ptr++) = 0;
		n--;
	}
}
