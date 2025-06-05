/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:12:52 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:44:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_memchr -- locate a byte in a memory block

DESCRIPTION
    The ft_memchr function scans the first `n` bytes of the memory area
    pointed to by `s` for the first occurrence of the byte `c`. The search
    is performed byte by byte.

PARAMETERS
    s: Pointer to the memory block to search.
    c: The byte to search for (converted to an unsigned char).
    n: The number of bytes to search.

RETURN VALUES
    - If the byte `c` is found, the function returns a pointer to its first
      occurrence in the memory block.
    - If the byte `c` is not found within the first `n` bytes, the function
      returns NULL.

NOTES
    - The function does not check for null terminators (`\0`) as it operates
      on raw memory, not null-terminated strings.
    - It is the caller's responsibility to ensure the memory block is valid
      and accessible for at least `n` bytes.

BUGS
    The behavior is undefined if `s` is NULL or if `n` exceeds the actual size
    of the memory block.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
