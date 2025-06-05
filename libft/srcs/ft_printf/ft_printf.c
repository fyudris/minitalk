/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:03:34 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/20 22:21:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * @brief Directing specifier to the correct print handler
 *
 * @param
 * @return
 */
int	ft_handle_format(char specifier, va_list args)
{
	if (specifier == '%')
		return (ft_print_char('%'));
	else if (specifier == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_LOWER));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_UPPER));
	else
		return (-1);
}

/**
 * @brief
 * %[parameter][flags][width][.precision][length]type
 * @param
 * @return
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			ret = ft_handle_format(*(++format), args);
		else
			ret = ft_print_char(*(format));
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
