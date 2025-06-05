/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:37:59 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:09 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	if (address == 0)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) < 0)
		return (-1);
	count = 2 + ft_print_hex(address, HEX_LOWER);
	if (count < 2)
		return (-1);
	return (count);
}
