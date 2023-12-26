/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:02:11 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/26 09:40:55 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(t_list	**lst) // Necessaire de faire un temp ?
{
	t_list* temp;

	if (!(*lst))
		return;
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
}

// void	del_nodes(t_list** lst)
// {
// 	t_list* temp;
// 	t_list* current;


// 	current = *lst;
// 	while (current)
// 	{
// 		temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// 	*lst = NULL;
// }

void	del_nodes(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (*lst)
	{
		*lst = temp->next;
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}

/*
Free memory :
- Fonction free nodes
- Fonction free list
*/
