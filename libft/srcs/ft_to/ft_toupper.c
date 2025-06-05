/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:43:27 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 22:33:46 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
    ft_toupper -- convert a lowercase letter to uppercase
    
DESCRIPTION
    The ft_toupper function converts a lowercase letter to its corresponding
    uppercase letter, if it exists. If the input character is not a lowercase
    letter, it is returned unchanged.

PARAMETERS
    c: The character to be converted.

RETURN VALUES
    If c is a lowercase letter ('a' to 'z'), the function returns its uppercase
    equivalent. Otherwise, the function returns c unchanged.

NOTES
    - The input character is expected to be representable as an unsigned char
      or EOF.
    - The function does not handle multibyte characters or non-ASCII input.
*/
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
