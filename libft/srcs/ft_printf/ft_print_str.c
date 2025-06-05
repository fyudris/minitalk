/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:14:03 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_str(const char *str)
{
	int		len;
	ssize_t	res;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	res = (write(1, str, len));
	if (res < 0)
		return (-1);
	return ((int) res);
}
