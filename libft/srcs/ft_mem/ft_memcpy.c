/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:12:28 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:06:04 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_memcpy -- copy memory area

DESCRIPTION
    The ft_memcpy function copies n bytes from the memory area pointed
    to by src to the memory area pointed to by dest. The memory areas
    should not overlap, as this may result in undefined behavior.

PARAMETERS
    dest: Pointer to the destination memory area.
    src: Pointer to the source memory area.
    n: Number of bytes to copy.

RETURN VALUES
    Returns a pointer to the destination memory area (dest).
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}
