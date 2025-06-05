/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:18:52 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:30:49 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    strchr -- locate the first occurrence of a character in a string

DESCRIPTION
    The ft_strchr function locates the first occurrence of the character `c`
    (converted to a char) in the string `s`. The null terminator `\0` is
    considered part of the string, so it can be searched for as well.

PARAMETERS
    s: The string to search within.
    c: The character to locate (passed as an int but treated as a char).

RETURN VALUE
    If the character `c` is found, a pointer to its first occurrence in `s`
    is returned. If `c` is not found, the function returns NULL.

NOTES
    - The input character `c` is cast to a char, allowing non-ASCII values to
      be processed, but the behavior for such values is undefined.
    - The function assumes that the input string `s` is null-terminated.

BUGS
    If the input string `s` is NULL, the behavior is undefined. It is the
    caller's responsibility to ensure the string is valid.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
