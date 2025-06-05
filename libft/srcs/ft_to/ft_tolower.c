/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:13:41 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 22:33:51 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
    ft_tolower -- convert an uppercase letter to lowercase
    
DESCRIPTION
    The ft_tolower function converts an uppercase letter to its corresponding
    lowercase letter, if it exists. If the input character is not an uppercase
    letter, it is returned unchanged.

PARAMETERS
    c: The character to be converted.

RETURN VALUES
    If c is an uppercase letter ('A' to 'Z'), the function returns its lowercase
    equivalent. Otherwise, the function returns c unchanged.

NOTES
    - The input character is expected to be representable as an unsigned char
      or EOF.
    - The function does not handle multibyte characters or non-ASCII input.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
