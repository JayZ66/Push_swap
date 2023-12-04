/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:17 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/21 17:51:38 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
/*
 * renvoi le + petit maillon pas encore trie
 * ou null si tout est trie
 */

t_list	*find_smallest_node(t_list **lst)
{
	t_list	*min; // Noeud qui stocke le plus petit nb actuel de la liste.
	t_list	*tmp_lst; // Clone liste pour iterer dedans.

	min = NULL;
	tmp_lst = *lst;
	while(tmp_lst)
	{
		if (tmp_lst->index == -1 && (min == NULL
			|| tmp_lst->content < min->content))
			min = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return(min);
}

/*
while(tmp_lst) // Tant qu'on est dans la liste.
	{
		if (tmp_lst->index == -1 && (min == NULL
			|| tmp_lst->content < min->content))
// Si l'index est egal a -1, c'est que le content (nb) a pas ete trie et indexe.
// Et si min == NULL, donc ne contient pas encore le content (nb) le + petit.
// Ou si min contient un nb, et que le contenu (nb) du noeud est inferieur
// au nb contenu dans le node min.
			min = tmp_lst; // Min prend la valeur de la liste tmp (+ petite val)
		tmp_lst = tmp_lst->next; // On passe au noeud suivant.
	}
	// On fait ca pour toute la liste, et a chq fois min recup. la + petite val.
*/

void	define_list_index(t_list **lst)
{
	t_list	*min;
	int		index;

	index = 1;
	while(1)
	{
		min = find_smallest_node(lst);
		if (min == NULL)
			return ;
		min->index = index;
		index++;
	}
}
