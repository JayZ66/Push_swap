/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:29 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/06 20:04:50 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	add_node(t_list **lst, int content)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	if (*lst == NULL) // Si rien dans la liste
		*lst = new_node;
	else // S'il y a deja des noeuds dans la liste.
	{ // On parcourt la liste et on ajoute le new node a la fin.
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	print_lst(const t_list *lst)
{
	const t_list	*current;

	current = lst;
	if (!lst)
		return ;
	while (current != NULL)
	{
		printf("from print_lst():%d (%d)\n", current->content, current->index);
		current = current->next;
	}
}

void	print_node(const t_list *lst)
{
	const t_list	*current;

	current = lst;
	if (!lst)
		return ;

	printf("from print_node(): %d (%d)\n", current->content, current->index);
}

// #include <stdlib.h>

// int	main(void)
// {
// 	t_list	*lst = NULL;

// 	add_node(&lst, -5);
// 	add_node(&lst, 3);
// 	add_node(&lst, 13);
// 	add_node(&lst, 10);
// 	add_node(&lst, 24);
// 	add_node(&lst, 16);
// 	add_node(&lst, 18);
// 	add_node(&lst, 9);

// 	define_list_index(&lst);
// 	printf("Voici la liste avant le push : \n");
// 	print_lst(lst);
// 	printf("\n");

// 	reverse_rotate_b(&lst, 1);


// 	printf("\nVoici la liste apres les modifications : \n");
// 	print_lst(lst);
// 	return (0);
// }

/*
Questions :
- Lorsque je fais mon push, les index sont attribues au debut
du coup quand je push le noeud de b vers a il y a deux index 1.
*/

int	main(void)
{
	t_list	*lsta = NULL;
	// t_list	*lstb = NULL;

	add_node(&lsta, 5);
	add_node(&lsta, 4);
	add_node(&lsta, 9);
	add_node(&lsta, 6);
	add_node(&lsta, 8);

	define_list_index(&lsta);
	printf("Voici la liste : \n");
	print_lst(lsta);
	printf("\n");

	print_node(find_smallest_index(&lsta));
	up_node(&lsta);
	printf("\nVoici la liste apres les modifications : \n");
	print_lst(lsta);
	write(1, "\n", 1);
	return (0);
}
