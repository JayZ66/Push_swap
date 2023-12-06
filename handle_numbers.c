/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:04:29 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/06 20:14:21 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list* handle_two_numbers(t_list** lsta)
{
	if (!(*lsta) || !(*lsta)->next)
		return (*lsta);

	int	first_index = (*lsta)->index;
	int	second_index = (*lsta)->next->index;

	if (first_index > second_index)
		swap_a(lsta, 1); // Appelle la fonction pour permuter les deux premiers noeuds

	// Appelle recursivement la fonction pour traiter le reste de la liste
	// (*lsta)->next = handle_two_numbers(&((*lsta)->next));

	return (*lsta); // Renvoie la liste potentiellement modifiee
}

// en traitant successivement les deux premiers elements et en appelant
// recursivement la fonction sur le reste de la liste. Cela continue jusqu'a
// ce que tous les elements soient tries.

t_list* handle_three_numbers(t_list** lsta)
{
	if (!(*lsta) || !(*lsta)->next)
		return (*lsta);
	int	first_index;
	int	second_index;
	int	last_index;

	first_index = (*lsta)->index;
	second_index = (*lsta)->next->index;
	last_index = (*lsta)->next->next->index;
	if ((first_index > second_index) && (second_index < last_index)
		&& (first_index < last_index))
		swap_a(lsta, 1);
	else if ((first_index > second_index) && (second_index > last_index)
		&& (first_index > last_index))
	{
		swap_a(lsta, 1);
		reverse_rotate_a(lsta, 1);
	}
	else if ((first_index > second_index) && (second_index < last_index)
		&& (first_index > last_index))
		rotate_a(lsta, 1);
	else if ((first_index < second_index) && (second_index > last_index)
		&& (first_index < last_index))
	{
		swap_a(lsta, 1);
		rotate_a(lsta, 1);
	}
	else if ((first_index < second_index) && (second_index > last_index)
		&& (first_index > last_index))
		reverse_rotate_a(lsta, 1);
	return (*lsta);
}


#include <stddef.h>

t_list	*find_smallest_index(t_list **lst)
{
	t_list	*min; // Noeud qui stocke le plus petit nb actuel de la liste.
	t_list	*tmp_lst; // Clone liste pour iterer dedans.

	if (!(*lst))
		return (NULL);
	min = *lst;
	tmp_lst = (*lst)->next;
	while (tmp_lst)
	{
		if (tmp_lst->index < min->index)
			min = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return (min);
}
// Maybe change name of index with power or ??
// SOIT je cree une fonction pour etablir les "vrais" index
// SOIT je travaille avec des next.
// SOIT dans ma structure je mets une var. pour la position.
t_list	*up_node(t_list	**lsta)
{
	t_list	*min;
	t_list	*first;

	if (!(*lsta))
		return (NULL);
	min = find_smallest_index(lsta);
	first = *lsta;
	if (min == first)
		return (*lsta);
	while ((*lsta)->next != min)
		*lsta = (*lsta)->next;
	(*lsta)->next = min->next;
	min->next = first->next;
	first->next = min;

	return (*lsta);
}

t_list	*up_node2(t_list **lsta) // Marche !
{
	t_list	*min;

	if (!(*lsta))
		return (NULL);
	min = find_smallest_index(lsta);
	while (*lsta != min)
		rotate_a(lsta, 1);
	return (*lsta);
}

/*
t_list	*up_node(t_list	**lsta)
{
	t_list	*min;

	if (!(*lsta) || !min)
		return (NULL);
	min = find_smallest_index(lsta);
	if (min->index == 2)
		swap_a(lsta, 1);
	else if (min->index == 3)
	{
		rotate_a(lsta, 1);
		swap_a(lsta, 1);
	}
	else if (min->index == 4)
	{
		reverse_rotate_a(lsta, 1);
		reverse_rotate_a(lsta, 1);
	}
	else if (min->index == 5)
		reverse_rotate_a(lsta, 1);
	return (*lsta);
}
*/

// Trouver les 2 +petits nb et mettre en haut pile a, mettre dans pile b (decroissant),
// trier pile a, puis tout remettre dans pile a.

// t_list* handle_five_numbers(t_list** lsta, t_list **lstb)
// {
// 	if (!(*lsta))
// 		return (*lsta);
// 	t_list	*min_index;

// 	min_index = find_smallest_node(lsta);
// 	FOnction 1 smallest node, return smallest node.
// 	Je la remonte en haut de la pile a, J'envoie cette node dans b.
// 	Je refais la meme pour le 2nd. (1er est extrait)

// 	handle_three_numbers(lsta);
// 	push_a(lsta, &min_index);
// 	push_a(lsta, &min_index2);

// 	return (*lsta);
// }

