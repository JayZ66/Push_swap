/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strokes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:07:54 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/05 11:38:01 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra(t_list **lst, int content) // Tout remonte.
{
	int count;
	t_list	*temp;

	if (!(*lst) || !lst)
		return (0);
	count = -1;
	temp = *lst;
	while (temp->content != content)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
// Penser a gerer le cas ou count_ra te renvoie -1, soit que content est en
// 1ere position.

int	count_rra(t_list **lst, int content) // Decale tout vers le bas.
{
	int	size;
	int	count;
	int result;
	t_list *temp;

	if (!(*lst) || !lst)
		return (0);
	size = lst_size(lst);
	count = 0;
	temp = *lst;
	while (temp->content != content)
	{
		count++;
		temp = temp->next;
	}
	result = (size - count) + 1; // +1 car on doit envoyer le dernier de la lst en haut.
	return (result);
}

