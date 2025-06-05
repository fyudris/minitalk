/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:09:16 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:37:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstsize -- count the number of elements in a linked list

DESCRIPTION
    The ft_lstsize function counts the number of nodes in the linked list
    pointed to by `lst`.

PARAMETERS
    lst: A pointer to the head of the linked list.

RETURN VALUES
    Returns the total number of nodes in the linked list.

NOTES
    - If `lst` is NULL, the function returns 0.

*/
int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
