/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:40:47 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_unsigned_int(unsigned int n)
{
	char	buffer[11];
	int		i;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	count = i;
	while (i > 0)
	{
		if (write(1, &buffer[--i], 1) < 0)
			return (-1);
	}
	return (count);
}
