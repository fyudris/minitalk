/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:48 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:13:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_substr -- extract a substring from a string

DESCRIPTION
    The ft_substr function allocates and returns a substring from the string `s`.
    The substring begins at index `start` and is of maximum length `len`.

PARAMETERS
    s: The string from which to extract the substring.
    start: The starting index of the substring in `s`.
    len: The maximum length of the substring.

RETURN VALUES
    - Returns a pointer to the newly allocated substring.
    - If the allocation fails or `s` is NULL, the function returns NULL.
    - If `start` is greater than the length of `s`, the function returns an
      empty string.

NOTES
    - The caller is responsible for freeing the allocated memory.
    - The function handles cases where `start` exceeds the string length and
      ensures proper null termination.

BUGS
    The function assumes that `s` is a valid null-terminated string. Passing
    an invalid pointer results in undefined behavior.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	alloc_len;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	alloc_len = s_len - start;
	if (alloc_len > len)
		alloc_len = len;
	str = ft_calloc(alloc_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < alloc_len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
