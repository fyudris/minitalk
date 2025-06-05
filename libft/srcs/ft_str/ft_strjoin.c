/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:23:45 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:18:39 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strjoin -- concatenate two strings into a new string

DESCRIPTION
    The ft_strjoin function allocates memory and returns a new string that is
    the result of the concatenation of `s1` and `s2`. The resulting string
    is null-terminated.

PARAMETERS
    s1: The first string to concatenate.
    s2: The second string to concatenate.

RETURN VALUES
    - Returns a pointer to the newly allocated string.
    - If memory allocation fails or if either `s1` or `s2` is NULL, the
      function returns NULL.

NOTES
    - The caller is responsible for freeing the allocated memory.
    - The function assumes that `s1` and `s2` are valid null-terminated strings.

BUGS
    The function does not handle NULL input strings. Adding a check for NULL
    inputs is recommended for robustness.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	result = (char *) malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	return (result);
}
