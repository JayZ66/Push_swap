/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:43:59 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/22 15:45:19 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	del_node(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
}


// Fonction de trie : Va assigner le premier index au nb le plus petit
// (index 0 = -10, index 1 = -2, etc.)

size_t	list_size(t_list *lst)
{
	size_t	length;

	length = 0;
	if (!lst || !lst->next)
		return (0);
	while (lst)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}

t_list	*lst_second_to_last(t_list **lst)
{
	t_list	*temp; // Des qu'on itere dans la liste il faut un tmp.

	temp = *lst;
	if (!(*lst) || !(*lst)->next)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_list	*lst_last(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	if (!(*lst))
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
