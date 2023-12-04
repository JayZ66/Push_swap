/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:53:17 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/21 17:50:56 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}	t_list;

void	swap_a(t_list **lsta, int print);
void	swap_b(t_list **lstb, int print);
void	swap_ab(t_list **lsta, t_list **lstb);
void	push_a(t_list **lsta, t_list **lstb);
void	push_b(t_list **lsta, t_list **lstb);
void	rotate_a(t_list **lsta, int print);
void	rotate_b(t_list	**lstb, int print);
void	rotate(t_list **lstb, t_list **lsta);
void	reverse_rotate_a(t_list **lsta, int print);
void	reverse_rotate_b(t_list **lstb, int print);
void	reverse_rotate(t_list **lsta, t_list **lstb);
t_list	*lst_last(t_list **lst);
t_list	*find_smallest_node(t_list **lst);
void	define_list_index(t_list **lst);

#endif
