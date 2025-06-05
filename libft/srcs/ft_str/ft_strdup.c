/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:48:57 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:05:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strdup -- duplicate a string

DESCRIPTION
    The ft_strdup function allocates memory and copies the string `s` into
    the newly allocated memory, including the null terminator.

PARAMETERS
    s: The null-terminated string to duplicate.

RETURN VALUES
    - On success, the function returns a pointer to the newly allocated
      memory containing the duplicated string.
    - If memory allocation fails, the function returns NULL.

NOTES
    - The caller is responsible for freeing the allocated memory.
    - The function does not handle NULL as input; passing NULL leads to
      undefined behavior.

BUGS
    The function assumes that the input string `s` is valid and
    null-terminated. Passing an invalid or NULL pointer leads to undefined
    behavior.
*/
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *) malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
