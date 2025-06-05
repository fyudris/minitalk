/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:26:11 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:48:56 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstlast -- get the last element of a linked list

DESCRIPTION
    The ft_lstlast function returns the last node of the linked list `lst`.

PARAMETERS
    lst: A pointer to the head of the linked list.

RETURN VALUES
    Returns a pointer to the last node of the list, or NULL if the list is empty.

NOTES
    - The function traverses the entire list, so its time complexity is O(n).
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tail;

	if (!lst)
		return (NULL);
	tail = lst;
	while (tail->next)
		tail = tail->next;
	return (tail);
}
