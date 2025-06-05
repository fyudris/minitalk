/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:44:25 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:51:28 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstadd_back -- add a new element to the end of a linked list

DESCRIPTION
    The ft_lstadd_back function adds the element `new` to the end of the
    linked list `lst`.

PARAMETERS
    lst: A pointer to the head of the linked list.
    new: The new element to add to the list.

RETURN VALUES
    None.

NOTES
    - If `lst` is NULL or `new` is NULL, the function does nothing.
    - If the list is empty, `new` becomes the head of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = ft_lstlast(*lst);
	tail->next = new;
}
