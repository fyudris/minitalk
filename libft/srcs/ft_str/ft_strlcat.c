/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:29:28 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 22:44:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strlcat -- concatenate strings with size-bounded buffer

DESCRIPTION
    The ft_strlcat function appends the string `src` to the end of `dst`.
    It ensures the resulting string is null-terminated as long as the buffer
    size `size` is greater than zero. The function will append at most
    `size - strlen(dst) - 1` bytes of `src` to `dst`.

    The function does not append anything if the size of the buffer `size`
    is less than or equal to the length of `dst`.

PARAMETERS
    dst: The destination string to which `src` is appended.
    src: The source string to append to `dst`.
    size: The total size of the destination buffer.

RETURN VALUES
    The ft_strlcat function returns the total length of the string it tried
    to create, which is the length of `dst` plus the length of `src`.
    If `size` is less than or equal to the length of `dst`, the return
    value is the length of `src` plus `size`.

NOTES
    - The caller must ensure that `dst` is properly null-terminated and the
      buffer is allocated with at least `size` bytes.
    - The function does not check for overlapping memory regions.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
