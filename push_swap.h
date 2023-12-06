/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:53:17 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/06 19:15:25 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// To remove
#include <stdio.h>


typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}	t_list;

int		len_num(int nb);
int		ft_atoi(char *str);
int		lst_size(t_list **lst);
int 	find_smallest(t_list **lst);
t_list 	*new_node(void *content);
t_list 	*lst_last(t_list **lst);
void 	lst_add_back(t_list **lst, t_list *new);
t_list 	*fill_lst(t_list **lst, int ac, char **av);
int		count_ra(t_list **lst, int content);
int		count_rra(t_list **lst, int content);
t_list	*handle_two_numbers(t_list** lsta);
t_list	*handle_three_numbers(t_list** lsta);
t_list	*find_smallest_node(t_list **lst);
void	define_list_index(t_list **lst);
void	push_a(t_list **lsta, t_list **lstb);
void	push_b(t_list **lsta, t_list **lstb);
void	reverse_rotate_a(t_list **lsta, int print);
void	reverse_rotate_b(t_list **lstb, int print);
void	reverse_rotate(t_list **lsta, t_list **lstb);
void	rotate_a(t_list **lsta, int print);
void	rotate_b(t_list	**lstb, int print);
void	rotate(t_list **lstb, t_list **lsta);
void	swap_a(t_list **lsta, int print);
void	swap_b(t_list **lstb, int print);
void	swap_ab(t_list **lsta, t_list **lstb);
void	del_node(t_list **lst);
t_list	*lst_second_to_last(t_list **lst);
t_list* handle_five_numbers(t_list** lsta, t_list **lstb);
t_list	*find_smallest_index(t_list **lst);
t_list	*up_node(t_list	**lsta);
t_list	*up_node2(t_list **lsta);

#endif
