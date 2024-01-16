/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:39:39 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 09:23:36 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length_highest_index(t_list *lsta)
{
	int		count;
	int		highest_nb;
	t_list	*highest_node;

	if (!lsta)
		return (0);
	count = 0;
	highest_node = find_highest_node(lsta);
	highest_nb = highest_node->index;
	if (highest_nb == 0)
		return (0);
	while (highest_nb != 0)
	{
		highest_nb /= 10;
		count++;
	}
	return (count);
}

int	is_sorted(t_list *lsta)
{
	t_list	*temp;

	if (!lsta)
		return (-1);
	temp = lsta;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	radix_sort_by_digit(t_list **lsta, t_list **lstb, int pos, int digit)
{
	int	i;
	int	list_size;
	int	current_index;
	int	current_position;

	i = 0;
	list_size = lst_size(*lsta);
	while (i < list_size)
	{
		current_index = (*lsta)->index;
		current_position = pos;
		while (current_position != 0)
		{
			current_index /= 10;
			current_position--;
		}
		if ((current_index % 10) == digit)
			push_b(lsta, lstb);
		else
			rotate_a(lsta, 1);
		i++;
	}
}

void	sort_hundred(t_list **lsta, t_list **lstb)
{
	int	rounds;
	int	digit;
	int	position;

	rounds = length_highest_index(*lsta);
	position = 0;
	while (position < rounds)
	{
		digit = 0;
		while (digit <= 9)
		{
			radix_sort_by_digit(lsta, lstb, position, digit);
			digit++;
		}
		while (*lstb)
			push_a(lsta, lstb);
		position++;
	}
}
