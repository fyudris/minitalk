/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:29:39 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:35 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
	ft_isalnum -- alphanumeric character test

DECRIPTION
    The ft_isalnum() function tests for any character for which ft_isalpha()
	or ft_isdigit() is true.
	The value of the argument must be resprensentable as an unsigned
	char or the value of EOF.

RETURN VALUES
    The ft_isalnum() function return zero if the character tests false
	and returns non-zero if the character tests true.
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
