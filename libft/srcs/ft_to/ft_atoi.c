/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:49:17 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:02:53 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
    ft_atoi -- convert a string to an integer

DESCRIPTION
    The ft_atoi function converts the initial portion of the string pointed
    to by `nptr` to an integer. The conversion ignores leading whitespace
    and handles an optional '+' or '-' sign.

    Conversion stops at the first non-digit character encountered after
    processing any leading whitespace and optional sign.

PARAMETERS
    nptr: The null-terminated string to be converted.

RETURN VALUES
    Returns the integer value of the string. If the string does not contain
    a valid integer representation, the function returns 0.

NOTES
    - The function does not handle overflows or underflows.
    - Characters after the valid numeric portion are ignored.

BUGS
    The behavior is undefined if the input string is NULL.
*/
static int	ft_iswhitespace(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	result *= sign;
	return (result);
}
