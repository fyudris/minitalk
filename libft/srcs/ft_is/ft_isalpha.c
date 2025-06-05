/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:52:13 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:08:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_isalpha() -- alphabetic character test

DECRIPTION
    The ft_isalpha() function tests for both upper- and lower-chased
    alhabetic character .
    The value of the argument must be resprensentable as an unsigned
    char or the value of EOF.

RETURN VALUES
    The isalpha() function return zero if the character tests false
	and returns non-zero if the character tests true.
*/
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
