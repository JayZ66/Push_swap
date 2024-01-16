/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:06:56 by jeguerin          #+#    #+#             */
/*   Updated: 2024/01/16 16:41:32 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_sorted(t_list *lsta, t_list *lstb)
{
	t_list	*temp;

	if (lstb)
		return (1);
	if (!lsta)
		return (1);
	temp = lsta;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	check_instructions(char *str, t_list **lsta, t_list **lstb)
{
	if (ft_strcmp(str, "pa\n") == 0)
		bonus_pa(lsta, lstb);
	else if (ft_strcmp(str, "pb\n") == 0)
		bonus_pb(lsta, lstb);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate_a(lsta, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate_b(lstb, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		bonus_rrr(lsta, lstb);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_a(lsta, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_b(lstb, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		bonus_ss(lsta, lstb);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_a(lsta, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_b(lstb, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		bonus_rr(lstb, lsta);
	else
		return (del_nodes(lsta), del_nodes(lstb));
}

void	check_final_stack(t_list **lsta, t_list **lstb, int i, char *str)
{
	if (i == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (str)
		free(str);
	if (!(*lsta) || !(*lstb))
		return ;
	del_nodes(lsta);
	del_nodes(lstb);
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	char	*result;

	lsta = NULL;
	lstb = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		argv = ft_split_ps(argv[1]);
		argc = array_len(argv);
	}
	else
		argv = ft_convert_format(argc, argv);
	if (fill_lst(&lsta, argc, argv) == NULL)
		return (-1);
	result = get_next_line(0);
	while (result)
	{
		check_instructions(result, &lsta, &lstb);
		free(result);
		result = get_next_line(0);
	}
	argc = is_sorted(lsta, lstb);
	return (check_final_stack(&lsta, &lstb, argc, argv[0]), 0);
}
