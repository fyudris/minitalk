/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:47:33 by fyudris           #+#    #+#             */
/*   Updated: 2025/06/04 14:54:07 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	size_t	old_size = 5 * sizeof(int);
	int		*arr = malloc(old_size);

	if (!arr)
		return (1);

	int i = 0;
	while (i < 5)
	{
		arr[i] = i + 1;
		i++;
	}

	printf("Original Array:\n");
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}

	size_t	new_size = 10 * sizeof(int);
	arr = ft_realloc(arr, old_size, new_size);

	if (!arr)
		return (1);

	i = 5;
	while (i < 10)
	{
		arr[i] = (i + 1) * 10;
		i++;
	}

	printf("\nNew Array:\n");
	i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}

	printf("\n");
	free(arr);
	return (0);
}
*/
