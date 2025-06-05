/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:50:56 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:29:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstnew -- create a new list node

DESCRIPTION
    The ft_lstnew function allocates memory and initializes a new linked list
    node. The `content` field of the node is initialized with the value of the
    `content` parameter, and the `next` pointer is set to NULL.

PARAMETERS
    content: The content to store in the new node.

RETURN VALUES
    Returns a pointer to the newly created node, or NULL if memory allocation
    fails.

NOTES
    - The `content` parameter can be any type of data (as a void pointer), so
      this function is versatile for different types of linked lists.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
