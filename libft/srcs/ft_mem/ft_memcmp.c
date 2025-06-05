/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:07:31 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:05:51 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_memcmp -- compare memory blocks byte by byte

DESCRIPTION
    The ft_memcmp function compares the first `n` bytes of the memory areas
    `s1` and `s2`. The comparison is performed lexicographically using the
    unsigned values of the bytes.

PARAMETERS
    s1: Pointer to the first memory area.
    s2: Pointer to the second memory area.
    n: The number of bytes to compare.

RETURN VALUES
    - Returns an integer less than, equal to, or greater than zero:
        - < 0: The first differing byte in `s1` is less than that in `s2`.
        - == 0: The memory areas are identical for the first `n` bytes.
        - > 0: The first differing byte in `s1` is greater than that in `s2`.

NOTES
    - The function does not stop at null terminators (`\0`) since it operates
      on raw memory, not strings.
    - The behavior is undefined if `n` exceeds the actual size of either
      memory block.

BUGS
    The function assumes both memory areas are valid for at least `n` bytes.
    If either `s1` or `s2` is invalid or too small, behavior is undefined.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) str1[i] != (unsigned char) str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}
