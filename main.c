/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:29 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/26 17:13:40 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int	main(void)
// {
// 	t_list	*lsta = NULL;
// 	t_list	*lstb = NULL;

// 	add_node(&lsta, 97);
// 	add_node(&lsta, 75);
// 	add_node(&lsta, 450);
// 	add_node(&lsta, 50);
// 	add_node(&lsta, 76);
// 	add_node(&lsta, 123);
// 	add_node(&lsta, 654);
// 	add_node(&lsta, 987);
// 	add_node(&lsta, 32);
// 	add_node(&lsta, 888);
// 	add_node(&lsta, 333);
// 	add_node(&lsta, 111);
// 	add_node(&lsta, 555);
// 	add_node(&lsta, 789);
// 	add_node(&lsta, 9876);
// 	add_node(&lsta, 5432);
// 	add_node(&lsta, 8765);
// 	add_node(&lsta, 1234);
// 	add_node(&lsta, 5678);
// 	add_node(&lsta, 9999);
// 	add_node(&lsta, 1111);
// 	add_node(&lsta, 2222);
// 	add_node(&lsta, 3333);
// 	add_node(&lsta, 4444);
// 	add_node(&lsta, 5555);
// 	add_node(&lsta, 6666);
// 	add_node(&lsta, 7777);
// 	add_node(&lsta, 8888);
// 	add_node(&lsta, 99999);
// 	add_node(&lsta, 12345);
// 	add_node(&lsta, 67890);
// 	add_node(&lsta, 13579);
// 	add_node(&lsta, 24680);
// 	add_node(&lsta, 11111);
// 	add_node(&lsta, 44444);
// 	add_node(&lsta, 77777);
// 	add_node(&lsta, 999999);
// 	add_node(&lsta, 888888);
// 	add_node(&lsta, 555555);
// 	add_node(&lsta, 123456);
// 	add_node(&lsta, 789012);
// 	add_node(&lsta, 345678);
// 	add_node(&lsta, 901234);
// 	add_node(&lsta, 567890);
// 	add_node(&lsta, 234567);
// 	add_node(&lsta, 876543);
// 	add_node(&lsta, 432109);
// 	add_node(&lsta, 987654);
// 	add_node(&lsta, 111111);
// 	add_node(&lsta, 222222);
// 	add_node(&lsta, 333333);
// 	add_node(&lsta, 444444);
// 	add_node(&lsta, 555444);
// 	add_node(&lsta, 666666);
// 	add_node(&lsta, 777777);
// 	add_node(&lsta, 878156);
// 	add_node(&lsta, 926587);
// 	add_node(&lsta, 101010);
// 	add_node(&lsta, 202020);
// 	add_node(&lsta, 303030);
// 	add_node(&lsta, 404040);
// 	add_node(&lsta, 505050);
// 	add_node(&lsta, 606060);
// 	add_node(&lsta, 707070);
// 	add_node(&lsta, 808080);
// 	add_node(&lsta, 909090);
// 	add_node(&lsta, 1234567);
// 	add_node(&lsta, 7654321);
// 	add_node(&lsta, 9876543);
// 	add_node(&lsta, 8765432);
// 	add_node(&lsta, 111222);
// 	add_node(&lsta, 333444);
// 	add_node(&lsta, 325698);
// 	add_node(&lsta, 777888);
// 	add_node(&lsta, 975318);
// 	add_node(&lsta, 864209);
// 	add_node(&lsta, 642087);
// 	add_node(&lsta, 531976);
// 	add_node(&lsta, 420865);
// 	add_node(&lsta, 309754);
// 	add_node(&lsta, 198643);
// 	add_node(&lsta, 87654);
// 	add_node(&lsta, 76543);
// 	add_node(&lsta, 68464);
// 	add_node(&lsta, 55323);
// 	add_node(&lsta, 98765);
// 	add_node(&lsta, 89824);
// 	add_node(&lsta, 78661);
// 	add_node(&lsta, 65432);
// 	add_node(&lsta, 54321);
// 	add_node(&lsta, 99145);
// 	add_node(&lsta, -10);
// 	add_node(&lsta, -100);
// 	add_node(&lsta, -1000);
// 	add_node(&lsta, -10000);
// 	add_node(&lsta, -10500);
// 	add_node(&lsta, 6);
// 	add_node(&lsta, 0);
// 	add_node(&lsta, -100000);
// 	add_node(&lsta, 15);

// 	define_list_index(&lsta);
// 	printf("Pas triee : %d\n", is_sorted(lsta));
// 	printf("Voici la liste : \n");
// 	print_lst(lsta);
// 	printf("\n");
// 	printf("Longeur de mon + grand nb : %d\n", length_highest_index(lsta));

// 	sort_hundred(&lsta, &lstb);
// 	printf("\nVoici la liste apres les modifications : \n");
// 	print_lst(lsta);
// 	// printf("Liste triee : %d\n", is_sorted(lsta));
// 	write(1, "\n", 1);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	verif si assez d'arguments
// 	verif' si un argument
//		Donc on split;
// 	verif si plus
// 		On convertit les args.
// 	verification si sorted
// 		Si pas le cas :
// 			On check si 2 nombres;
// 				handle_two_numbers;
// 			On check si 3 nombres;
// 				sort_three_numbers;
// 			On check si 4 ou 5 nombres
// 				sort_five_numbers;
// 			On check si superieur;
// 				tri_radix;
// }

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	char	**result;

	lsta = NULL;
	lstb = NULL;
	result = NULL;
	if (argc < 2 || !argv[1][0])
	{
		write(1, "Number of args\n", 15);
		return (-1);
	}
	if (argc == 2)
		result = ft_split(argv[1]);
	else
		result = ft_convert_format(argc, argv); // To convert args. received.
	if (fill_lst(&lsta, argc, result) == NULL) // Or ARGV.
		return (-1);
	if (!is_sorted(lsta))
	{
		if (lst_size(lsta) == 2)
			handle_two_numbers(&lsta);
		else if (lst_size(lsta) == 3)
			sort_three_numbers(&lsta);
		else if (lst_size(lsta) <= 5)
			sort_five_numbers(&lsta, &lstb);
		else if (lst_size(lsta) <= 100)
			sort_hundred(&lsta, &lstb);
	}
	print_lst(lsta);
	del_nodes(&lsta);
	return (0);
}

/*
TESTS FAILED :
- Quand nombres en double. => OK
- Tri 100 : Trop de coups (1300)
- Gerer si int dans mon atoi. => OK
- Gerer si min/max int => OK
- Gerer les " " avec split = un arg.
- Gerer les leaks de memoire => OK
- Gerer le cas ou on a : " 45 78 35" "45 64 87" !

QUESTIONS :
- Pourquoi en retirant le pointeur, toute ma lst est print.
*/






// Free split si utilise.

// Check also si nb sont pas un int ! => TO DO ! But where ?

