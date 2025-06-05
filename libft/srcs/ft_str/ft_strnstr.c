/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:04:05 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 13:55:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strnstr -- locate a substring in a string within a limited length

DESCRIPTION
    The ft_strnstr function locates the first occurrence of the null-terminated
    string `little` in the string `big`, where no more than `len` characters
    are searched. Characters after `len` are not searched.

    If `little` is an empty string, `big` is returned. If `little` occurs
    nowhere in `big`, NULL is returned.

PARAMETERS
    big: The string to be searched.
    little: The substring to search for.
    len: The maximum number of characters to search.

RETURN VALUES
    - Returns a pointer to the first occurrence of `little` in `big`.
    - If `little` is an empty string, `big` is returned.
    - If `little` is not found in the first `len` characters of `big`, the
      function returns NULL.

NOTES
    - Both `big` and `little` must be null-terminated strings.
    - The comparison stops at the first mismatch, end of `big`, or after
      `len` characters, whichever comes first.

BUGS
    The function assumes `big` and `little` are valid pointers. If either is
    NULL, the behavior is undefined.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		while ((big[i + j] == little[j]) && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
