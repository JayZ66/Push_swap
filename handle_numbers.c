/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:51:37 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/12 19:46:00 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_two_numbers(t_list **lsta)
{
	if (!(*lsta) || !(*lsta)->next)
		return ;

	int	first_index = (*lsta)->index;
	int	second_index = (*lsta)->next->index;

	if (first_index > second_index)
		swap_a(lsta, 1); // Appelle la fonction pour permuter les deux premiers noeuds
}

// Fonction qui trouve le plus petit noeud.

t_list	*find_smallest_node(t_list *lst)
{
	int		min_node;
	t_list	*smallest_node; // Allow to return & keep the smallest node.

	if (!lst)
		return (NULL);
	min_node = INT_MAX;
	smallest_node = NULL;
	while (lst)
	{
		if (lst->content < min_node)
		{
			min_node = lst->content;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}

// Fonction qui trouve le plus grand noeud.

t_list	*find_highest_node(t_list *lst)
{
	int		max_node;
	t_list	*highest_node;

	if (!lst)
		return (NULL);
	max_node = INT_MIN;
	highest_node = NULL;
	while (lst)
	{
		if (lst->content > max_node)
		{
			max_node = lst->content;
			highest_node = lst;
		}
		lst = lst->next;
	}
	return (highest_node);
}

// Fonction qui gere le tri de 3 nombres.
/*
The aim of this function is to find the biggest node, then to move it at the
end of the stack, and finally to compare the two first numbers and to sort it.
*/

void	sort_three_numbers(t_list **lsta)
{
	t_list	*highest_node;

	if (!(*lsta))
		return ;
	highest_node = find_highest_node(*lsta);
	if ((*lsta) == highest_node)
		rotate_a(lsta, 1);
	else if ((*lsta)->next == highest_node)
		reverse_rotate_a(lsta, 1);
	if ((*lsta)->content > (*lsta)->next->content)
		swap_a(lsta, 1);
}

t_list	*find_second_smallest_node(t_list *lsta)
{
	t_list	*first_smallest_node;
	int		second_smallest_value;
	t_list	*second_smallest_node;
	t_list	*tmp;

	first_smallest_node = find_smallest_node(lsta);
	second_smallest_value = INT_MAX;
	second_smallest_node = NULL;
	tmp = lsta;
	while (tmp)
	{
		if ((tmp != first_smallest_node)
			&& (tmp->content < second_smallest_value))
		{
			second_smallest_value = tmp->content;
			second_smallest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (second_smallest_node);
}


// Fonction qui push les 2 plus petits nombres en bas de la pile.

void	push_smallests_at_the_bottom(t_list	**lsta)
{
	t_list	*first_smallest_node;
	t_list	*second_smallest_node;
	t_list	*tmp;

	if (!(*lsta) && !(*lsta)->next)
		return ;
	first_smallest_node = find_smallest_node(*lsta);
	second_smallest_node = find_second_smallest_node(*lsta);
	tmp = *lsta;
	tmp = tmp->next;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if ((tmp == second_smallest_node) && (tmp->next == first_smallest_node))
		{
			reverse_rotate_a(lsta, 1);
			reverse_rotate_a(lsta, 1);
		}
	}
}

/*
Si jamais smallest est le dernier noeud et second smallest l'avant dernier, alors on le remonte en haut.
Pour enlever les 2 nodes au départ, on itterre sur toute ma liste puis on remonte la node,
sauf dans ce cas precis, ça faisait trop de coups.
*/


// Fonction qui gere le tri 5 nombres.

void	sort_five_numbers(t_list **lsta, t_list **lstb)
{
	t_list	*smallest_node;
	int		count;
	int		stack_size;

	if (!(*lsta) || !(*lsta)->next)
		return;
	count = 0;
	stack_size = lst_size(*lsta);
	push_smallests_at_the_bottom(lsta);
	while (count++ < stack_size - 3)
	{
		smallest_node = find_smallest_node(*lsta);
		while (*lsta != smallest_node)
			rotate_a(lsta, 1);
		push_b(lsta, lstb);
	}
	sort_three_numbers(lsta);
	if (stack_size == 5)
	{
		smallest_node = find_smallest_node(*lstb);
		if (*lstb == smallest_node)
			swap_b(lstb, 1);
		push_a(lsta, lstb);
	}
	push_a(lsta, lstb);
}

/*
The aim of the fonction is to sort a stack of five numbers.
To do it, first i'm gonna bring the 2 smallest numbers to the top of the stack.
Then i'll push them in stack b, to sort stack a with my sort_three_numbers function.
Finally, i'll check if my numbers in stack b are sorted, if not i'll sort them and push them in stack a.
*/


// Je deplace mon deuxieme plus petit noeud, jusqu'a different de NULL
// Je deplace mon premier jusqu'a ce que first node ->next == second
