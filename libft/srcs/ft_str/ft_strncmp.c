/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:07:26 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:40:40 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strncmp -- compare strings up to a specified number of characters

DESCRIPTION
    The ft_strncmp function compares up to `n` characters of the strings `s1`
    and `s2`. The comparison is performed lexicographically using unsigned
    character values.

PARAMETERS
    s1: The first string to compare.
    s2: The second string to compare.
    n: The maximum number of characters to compare.

RETURN VALUES
    - Returns an integer less than, equal to, or greater than zero:
        - < 0: `s1` is less than `s2`.
        - == 0: The strings are equal up to `n` characters.
        - > 0: `s1` is greater than `s2`.

NOTES
    - If `n` is 0, the function returns 0 immediately.
    - The comparison stops at the first difference, a null terminator, or after
      comparing `n` characters, whichever comes first.
    - The function uses unsigned character values to ensure proper handling
      of extended ASCII and non-ASCII characters.

BUGS
    The behavior is undefined if `s1` or `s2` is not null-terminated and `n`
    exceeds the actual length of either string.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
