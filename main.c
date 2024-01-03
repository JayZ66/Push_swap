/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:29 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 13:24:11 by jeguerin         ###   ########.fr       */
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
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	sort_lst(t_list **lsta, t_list **lstb)
{
	if (!is_sorted(*lsta))
	{
		if (lst_size(*lsta) == 2)
			handle_two_numbers(lsta);
		else if (lst_size(*lsta) == 3)
			sort_three_numbers(lsta);
		else if (lst_size(*lsta) <= 5)
			sort_five_numbers(lsta, lstb);
		else if (lst_size(*lsta) <= 500)
			sort_hundred(lsta, lstb);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	char	**result;

	lsta = NULL;
	lstb = NULL;
	result = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		result = ft_split(argv[1]);
		argc = array_len(result);
	}
	else
		result = ft_convert_format(argc, argv);
	if (fill_lst(&lsta, argc, result) == NULL)
		return (-1);
	sort_lst(&lsta, &lstb);
	del_nodes(&lsta);
	return (0);
}
