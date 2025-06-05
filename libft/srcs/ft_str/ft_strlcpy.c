/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:50:44 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 22:33:38 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strlcpy -- copy a string to a sized buffer

DESCRIPTION
    The ft_strlcpy function copies up to size - 1 characters from the
    null-terminated string src to the buffer dst, null-terminating the
    result. The function is designed to be safer and more consistent
    than strncpy.

PARAMETERS
    dst: Pointer to the destination buffer.
    src: Pointer to the null-terminated source string.
    size: Size of the destination buffer.
    
RETURN VALUES
    Returns the total length of the string src. If the return value is
    greater than or equal to size, truncation occurred.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
