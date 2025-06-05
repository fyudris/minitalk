/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:52:31 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 22:33:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strrchr -- locate the last occurrence of a character in a string

DESCRIPTION
    The ft_strrchr function locates the last occurrence of the character `c`
    (converted to a char) in the string `s`. The null terminator character `\0`
    is considered part of the string, so it can be searched for as well.

PARAMETERS
    s: The string in which to search for the character `c`.
    c: The character to search for (passed as an int but treated as a char).

RETURN VALUES
    If the character `c` is found, the function returns a pointer to its last
    occurrence in the string `s`. If the character is not found, the function
    returns NULL.

NOTES
    - The input character `c` is cast to a char, allowing non-ASCII values to
      be processed, but the behavior for such values is undefined.
    - The function assumes that the input string `s` is null-terminated.

BUGS
    If the input string `s` is NULL, the behavior is undefined. It is the
    caller's responsibility to ensure the string is valid.
*/

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*current_cc;

	cc = (char) c;
	i = 0;
	current_cc = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			current_cc = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		current_cc = (char *) &s[i];
	return (current_cc);
}
