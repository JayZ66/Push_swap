/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:03 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 09:23:27 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lstb))
		return ;
	write(1, "pa\n", 3);
	temp = (*lstb);
	(*lstb) = (*lstb)->next;
	temp->next = (*lsta);
	(*lsta) = temp;
}

void	push_b(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lsta))
		return ;
	write(1, "pb\n", 3);
	temp = (*lsta);
	(*lsta) = (*lsta)->next;
	temp->next = (*lstb);
	(*lstb) = temp;
}
