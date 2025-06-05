/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:47:59 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 14:45:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_itoa -- convert an integer to a string

DESCRIPTION
    The ft_itoa function converts an integer `n` to a null-terminated
    string representation. The function dynamically allocates memory
    for the resulting string, which must be freed by the caller.

PARAMETERS
    n: The integer to convert.

RETURN VALUES
    - A pointer to the newly allocated string containing the string
      representation of `n`.
    - NULL if memory allocation fails.

NOTES
    - The function handles negative numbers and returns a string
      containing the '-' character if `n` is negative.
    - The caller is responsible for freeing the allocated memory.

BUGS
    The function assumes valid integer input. Passing invalid data
    or extreme edge cases like INT_MIN without `long` conversion
    could result in undefined behavior.
*/

static int	get_num_length(int n);
static char	*allocate_string(int len);
static void	fill_string_with_number(char *str, long num, int len);

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*result;

	num = n;
	len = get_num_length(num);
	result = allocate_string(len);
	if (!result)
		return (NULL);
	fill_string_with_number(result, num, len);
	return (result);
}

/**
* Calculates the length of the number including '-' if negative.
*/
static int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
* Allocate memory for a string of length `len` and null-terminates it.
*/
static char	*allocate_string(int len)
{
	char	*str;

	str = (char *) malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

/**
* Fills the string `str` with the characters of the number `num`.
*/
static void	fill_string_with_number(char *str, long num, int len)
{
	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
}
