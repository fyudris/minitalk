/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:54 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:07 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_int(int n)
{
	int		count;
	char	c;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		count++;
		n = -n;
	}
	if (n > 9)
	{
		count += ft_print_int(n / 10);
		if (count < 0)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) < 0)
		return (-1);
	count++;
	return (count);
}
