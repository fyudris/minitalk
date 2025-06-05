/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:55:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/10 00:10:25 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstmap -- create a new list by applying a function to each node's content

DESCRIPTION
    The ft_lstmap function creates a new linked list by applying the function `f`
    to the content of each node in the original list. The `del` function is used
    to free the content in case of an allocation failure.

PARAMETERS
    lst: A pointer to the head of the original linked list.
    f:   A function to apply to the content of each node.
    del: A function to free the content in case of allocation failure.

RETURN VALUES
    Returns a pointer to the head of the new list, or NULL if the allocation 
	fails.

NOTES
    - The function does not modify the original list.
    - The `f` function should allocate memory for the new content if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
