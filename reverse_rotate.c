/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:58:17 by jeguerin          #+#    #+#             */
/*   Updated: 2024/01/02 18:06:15 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **lsta, int print)
{
	t_list	*last_to_first;
	t_list	*new_last;
	t_list	*temp;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	temp = *lsta;
	last_to_first = lst_last(temp);
	new_last = lst_second_to_last(lsta);
	last_to_first->next = (*lsta);
	(*lsta) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

//Temp utile car j'envoyais *lsta, donc l'add. de ma liste,
// ce qui modifiait l'ensemble et non en local.

void	reverse_rotate_b(t_list **lstb, int print)
{
	t_list	*last_to_first;
	t_list	*new_last;
	t_list	*temp;

	if (!(*lstb) || !(*lstb)->next)
		return ;
	temp = *lstb;
	last_to_first = lst_last(temp);
	new_last = lst_second_to_last(lstb);
	last_to_first->next = (*lstb);
	(*lstb) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	reverse_rotate(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb) || !(*lsta)->next || !(*lstb)->next)
		return ;
	write(1, "rrr\n", 4);
	reverse_rotate_a(lsta, 0);
	reverse_rotate_b(lstb, 0);
}
