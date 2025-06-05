/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:38:46 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:09:19 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_calloc -- allocate and zero-initialize memory
    
DESCRIPTION
    The ft_calloc function allocates memory for an array of nmemb elements,
    each of size bytes. The allocated memory is initialized to zero.

    It is similar to malloc, but it also initializes the allocated 
	memory to zero.

PARAMETERS
    nmemb: Number of elements to allocate.
    size: Size of each element in bytes.

RETURN VALUES
    Returns a pointer to the allocated memory. If the allocation fails or
    if the result of nmemb * size exceeds the limits of size_t, the function
    returns NULL.

NOTES
    - This implementation checks for integer overflow during the allocation.
    - Memory allocated with ft_calloc must be freed using free.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	i = 0;
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i < nmemb * size)
		((unsigned char *)temp)[i++] = 0;
	return (temp);
}
