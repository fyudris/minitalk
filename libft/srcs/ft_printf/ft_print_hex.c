/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:32:26 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_hex(unsigned long long n, const char *base)
{
	unsigned long long	base_len;
	int					count;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
	{
		count += ft_print_hex(n / base_len, base);
		if (count < 0)
			return (-1);
	}
	if (write(1, &base[n % base_len], 1) < 0)
		return (-1);
	count++;
	return (count);
}
