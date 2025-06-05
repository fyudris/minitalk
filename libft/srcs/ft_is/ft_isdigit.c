/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:24:20 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:44 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_isdigit() -- alphabetic character test

DECRIPTION
    The ft_isdigit() function tests for a decimal digit character.
	The value of the argument must be resprensentable as an unsigned
	char or the value of EOF.

RETURN VALUES
    The ft_isdigit() function return zero if the character tests false
	and returns non-zero if the character tests true.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
