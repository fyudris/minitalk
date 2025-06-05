/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:46:55 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:25:53 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strtrim -- trim characters from the start and end of a string

DESCRIPTION
    The ft_strtrim function removes all characters from the start and end
    of the string `s1` that are found in the string `set`. The resulting
    string is newly allocated and null-terminated.

PARAMETERS
    s1: The input string to be trimmed.
    set: The set of characters to trim from the start and end of `s1`.

RETURN VALUES
    - Returns a pointer to the trimmed string.
    - If memory allocation fails, the function returns NULL.
    - If `s1` is an empty string or if all characters are trimmed, the function
      returns an empty string.

NOTES
    - The caller is responsible for freeing the allocated memory.
    - If either `s1` or `set` is NULL, the function returns NULL.

BUGS
    The function assumes that `s1` and `set` are valid null-terminated strings.
    Passing invalid pointers leads to undefined behavior.
*/
static int	is_to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*create_trimstr(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && is_to_trim(set, s1[i]))
		i++;
	while (j >= i && is_to_trim(set, s1[j]))
		j--;
	return (create_trimstr(s1, i, j - i + 1));
}
