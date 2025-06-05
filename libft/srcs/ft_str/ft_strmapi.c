/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:25:19 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:51:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_strmapi -- apply a function to each character of a string

DESCRIPTION
    The ft_strmapi function applies the function `f` to each character of the
    string `s` to create a new string (with malloc) resulting from successive
    applications of `f`.

PARAMETERS
    s: The input string to iterate over.
    f: The function to apply to each character. It takes two arguments:
       - The character's index (unsigned int).
       - The character itself.

RETURN VALUES
    - A pointer to the newly allocated string containing the transformed
      characters.
    - NULL if the allocation fails or if `s` or `f` is NULL.

NOTES
    - The caller is responsible for freeing the allocated memory.
    - The function assumes `s` is a valid null-terminated string.

BUGS
    The function assumes valid input strings. Passing NULL or invalid pointers
    may result in undefined behavior.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*result;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = (char *) malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
