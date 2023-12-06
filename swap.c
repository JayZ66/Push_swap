/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:51 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/06 19:47:50 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// void swap_a(t_list **lsta, int print)
// {
// 	if (!lsta || !(*lsta) || !(*lsta)->next)
// 		return;

// 	printf("min's index: %d\n", (*lsta)->index);
// 	printf("min's index next: %d\n", (*lsta)->next->index);

// 	int	tmp = (*lsta)->next->content;
// 	(*lsta)->next->content = (*lsta)->content;
// 	(*lsta)->content = tmp;

// 	if (print == 1)
// 		write(1, "sa\n", 3);
// }

void	swap_a(t_list **lsta, int print)
{
	t_list	*temp;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	temp = (*lsta);
	(*lsta) = temp->next;
	temp->next = (*lsta)->next;
	(*lsta)->next = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **lstb, int print)
{
	t_list	*temp;

	if (!(*lstb) || !(*lstb)->next)
		return ;
	temp = (*lstb);
	(*lstb) = temp->next;
	temp->next = (*lstb)->next;
	(*lstb)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb))
		return ;
	write(1, "ss\n", 3);
	swap_a(lsta, 0);
	swap_b(lstb, 0);
}
