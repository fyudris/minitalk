/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:51:20 by fyudris           #+#    #+#             */
/*   Updated: 2025/02/24 15:37:56 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_handle_format(char specifier, va_list args);
int		ft_print_char(char c);
int		ft_print_str(const char *str);
int		ft_print_int(int n);
int		ft_print_unsigned_int(unsigned int n);
int		ft_print_pointer(void *ptr);
int		ft_print_hex(unsigned long long n, const char *base);
size_t	ft_strlen(const char *str);

#endif
