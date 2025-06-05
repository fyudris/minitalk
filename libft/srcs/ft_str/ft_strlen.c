/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:22 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:07:30 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
	ft_strlen -- find length of string

DECRIPTION
    The ft_strlen() function computes the length of the string s.

RETURN VALUES
    The ft_strlen() function returns the number of characters that precede 
	the terminating NUL character.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
