/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:54:08 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 15:02:12 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
    ft_striteri -- apply a function to each character of a string (in-place)

DESCRIPTION
    The ft_striteri function iterates through the string `s` and applies the
    function `f` to each character. The function `f` is passed the index of
    the character and a pointer to the character itself, allowing in-place
    modification.

PARAMETERS
    s: The input string to iterate over.
    f: The function to apply to each character. It takes two arguments:
       - The character's index (unsigned int).
       - A pointer to the character (char*), allowing direct modification.

RETURN VALUES
    None.

NOTES
    - The function modifies the string `s` directly.
    - If either `s` or `f` is NULL, the function does nothing.

BUGS
    The function assumes `s` is a valid null-terminated string. Passing NULL
    or invalid pointers results in undefined behavior.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
