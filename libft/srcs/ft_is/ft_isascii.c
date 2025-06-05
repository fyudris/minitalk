/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:32:24 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:40 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_isascii -- test for ASCII character

DECRIPTION
    The ft_isascii() function tests for an ASCII character, 
	which is any character between 0 and octal 127 decimal inclusive.

RETURN VALUES
    The ft_isascii() function return zero if the character tests false
	and returns non-zero if the character tests true.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
