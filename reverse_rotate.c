/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:58:17 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/04 19:02:01 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



void	reverse_rotate_a(t_list **lsta, int print)
{
	t_list	*last_to_first;
	t_list	*new_last;

	if (!(*lsta) || !(*lsta)->next)
		return ;
	last_to_first = lst_last(lsta);
	new_last = lst_second_to_last(lsta);
	last_to_first->next = (*lsta);
	(*lsta) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **lstb, int print)
{
	t_list	*last_to_first;
	t_list	*new_last;

	if (!(*lstb) || !(*lstb)->next)
		return ;
	last_to_first = lst_last(lstb);
	new_last = lst_second_to_last(lstb);
	last_to_first->next = (*lstb);
	(*lstb) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate(t_list **lsta, t_list **lstb)
{
	if (!(*lsta) || !(*lstb) || !(*lsta)->next || !(*lstb)->next)
		return ;
	write(1, "rrr\n", 4);
	reverse_rotate_a(lsta, 0);
	reverse_rotate_b(lstb, 0);
}

// Utiliser ** lorsqu'on realise un action qui impact les deux piles
// car doit avoir un impact sur l'ensemble de la "structure" et * si on
// travaille sur une liste(pile).


// Reverse rotate a
	// On fait pointer le dernier noeud vers le premier.
	// On initialise le dernier noeud en premier.
	// On initialise l'avant dernier noeud en dernier.
