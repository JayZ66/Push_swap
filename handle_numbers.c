/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:04:29 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/01 17:05:07 by jeguerin         ###   ########.fr       */
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
	(*lsta)->next = handle_two_numbers(&((*lsta)->next));

	return (*lsta); // Renvoie la liste potentiellement modifiee
}

// en traitant successivement les deux premiers elements et en appelant
// recursivement la fonction sur le reste de la liste. Cela continue jusqu'a
// ce que tous les elements soient tries.

t_list* handle_three_numbers(t_list** lsta)
{
	if (!(*lsta) || !(*lsta)->next)
		return (*lsta) OU NULL ?
	int	first_index;
	int	second_index;
	int	last_index;

	first_index = (*lsta)->index;
	second_index = (*lsta)->next->index;
	last_index = (*lsta)->next->next->index;
	if ((first_index > second_index) && (second_index < last_index)
		&& (first_index < last_index))
		swap_a(lsta, 1);
	else if ((first_index > second_index) && (second_index > last_index)) // REVOIR
	{
		swap_a(lsta, 1);
		reverse_rotate_a(lsta, 1); // Est-ce qu'il faut add un if pour le 2nde etape ?
	}
	else if ((first_index > second_index) && (second_index < last_index)
		&& (first_index > last_index))
		rotate_a(lsta, 1);
	else if ((first_index < second_index) && (second_index > last_index)) // REVOIR
	{
		swap_a(lsta, 1);
		rotate_a(lsta, 1); // Est-ce qu'il faut add un if pour le 2nde etape ?
	}
	else if ((first_index < second_index) && (second_index > last)
		&& (first_index > last_index))
		reverse_rotate(lsta, 1);

}
