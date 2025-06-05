/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:03:11 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/09 23:35:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NAME
    ft_lstadd_front -- add a new element to the beginning of a linked list

DESCRIPTION
    The ft_lstadd_front function adds the element `new` to the beginning of
    the linked list `lst`.

PARAMETERS
    lst: A pointer to the head of the linked list.
    new: The new element to add to the list.

RETURN VALUES
    None.

NOTES
    - If `lst` is NULL or `new` is NULL, the function does nothing.
    - The `new` element becomes the new head of the list.

*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
