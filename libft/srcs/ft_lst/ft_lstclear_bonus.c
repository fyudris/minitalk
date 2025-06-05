/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:01:30 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:01:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstclear -- delete and free all nodes in a linked list

DESCRIPTION
    The ft_lstclear function deletes and frees all nodes in the linked list
    pointed to by `lst`. Each node's content is freed using the `del` function.
    The list head is set to NULL after all nodes are cleared.

PARAMETERS
    lst: A pointer to the head of the linked list.
    del: A pointer to a function used to free the content of each node.

RETURN VALUES
    None.

NOTES
    - The `del` function should free the content of each node.
    - If `lst` or `del` is NULL, the function does nothing.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tail;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tail = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tail;
	}
	*lst = NULL;
}
