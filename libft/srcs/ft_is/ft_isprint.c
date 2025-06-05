/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:34:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	ft_isprint() -- printing character test (space character inclusive)

DECRIPTION
    The ft_isprint() function checks whether the character c falls within the
	printable ASCII range (32 to 126, inclusive).
	The value of the argument must representable as an unsigned char or the value
	of EOF.

RETURN VALUES
    The ft_isprint() function returns zero if the character tests false and
	returns non-zero if the character tests true.

*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
