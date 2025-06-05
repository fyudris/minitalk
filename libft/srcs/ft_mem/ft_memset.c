/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:44:29 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:06:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_memset -- fill a byte string with a byte value
D
ESCRIPTION
    The ft_memset function fills the first n bytes of the memory area pointed
	to by s with the constant byte value c (converted to unsigned char).
	It is commonly used to initialize or reset memory blocks efficient

PARAMETER
	s: Pointer to the memory area to be filled.
	c: Byte value to set, converted to unsigned char.
	n: Number of bytes to set.

RETURN VALUES
    Returns the original pointer s to the memory area.
	*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*(ptr++) = (unsigned char) c;
		n--;
	}
	return (s);
}
