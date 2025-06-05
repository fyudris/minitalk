/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:54:01 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:59:01 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstdelone -- delete a single node from a linked list

DESCRIPTION
    The ft_lstdelone function deletes a single node from a linked list. The
    content of the node is freed using the provided `del` function, and the
    node itself is then freed.

PARAMETERS
    lst: The node to delete.
    del: A pointer to a function used to free the content of the node.

RETURN VALUES
    None.

NOTES
    - The `del` function should free the content of the node but not the node
      itself; freeing the node is handled by `ft_lstdelone`.
    - If `lst` or `del` is `NULL`, the function does nothing.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
