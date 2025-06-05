/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:31 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:06:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_memmove -- copy memory area handling overlaps

DESCRIPTION
    The ft_memmove function copies n bytes from the memory area pointed
    to by src to the memory area pointed to by dest. The memory areas
    may overlap, and the copy is performed in a safe manner to avoid data
    corruption.
	It is similar to ft_memcpy, but it can handle overlapping memory regions
	safely, making it more versatile.

PARAMETERS
    dest: Pointer to the destination memory area.
    src: Pointer to the source memory area.
    n: Number of bytes to copy.

RETURN VALUES
    Returns a pointer to the destination memory area (dest).
*/
static void	move_backward(char *dest, const char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

static void	move_forward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	if ((char *)dest > (char *)src)
		move_backward((char *)dest, (const char *)src, n);
	else
		move_forward((char *)dest, (const char *)src, n);
	return (dest);
}
