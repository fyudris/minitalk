/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:47:55 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:05:36 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstiter -- iterate over a linked list and apply a function to each node

DESCRIPTION
    The ft_lstiter function iterates over a linked list and applies the
    function `f` to the `content` of each node.

PARAMETERS
    lst: A pointer to the head of the linked list.
    f:   A function to apply to the content of each node.

RETURN VALUES
    None.

NOTES
    - The function does nothing if `lst` is NULL.
    - The provided function `f` must not modify the structure of the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
