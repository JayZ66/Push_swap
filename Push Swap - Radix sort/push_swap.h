/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:53:17 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 11:58:46 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}	t_list;

// Instructions
void		push_a(t_list **lsta, t_list **lstb);
void		push_b(t_list **lsta, t_list **lstb);
void		reverse_rotate_a(t_list **lsta, int print);
void		reverse_rotate_b(t_list **lstb, int print);
void		reverse_rotate(t_list **lsta, t_list **lstb);
void		rotate_a(t_list **lsta, int print);
void		rotate_b(t_list	**lstb, int print);
void		rotate(t_list **lstb, t_list **lsta);
void		swap_a(t_list **lsta, int print);
void		swap_b(t_list **lstb, int print);
void		swap_ab(t_list **lsta, t_list **lstb);

// Utils
int			ft_atoi(char *str);
int			lst_size(t_list *lst);
int			count_words(char *str);
int			ft_strlen(char *str);
int			check_doublons(t_list *lst);
int			check_is_digit(const char *str);
int			check_digit_size(long long digit);
int			array_len(char **arr);
void		define_list_index(t_list **lst);
void		lst_add_back(t_list **lst, t_list *new);
void		push_smallests_at_the_bottom(t_list	**lsta);
void		del_nodes(t_list **lst);
void		ft_free_array(char **arr);
t_list		*new_node(int content);
t_list		*lst_last(t_list *lst);
t_list		*fill_lst(t_list **lst, int ac, char **av);
t_list		*find_smallest_nb(t_list **lst);
t_list		*lst_second_to_last(t_list **lst);
t_list		*find_smallest_node(t_list *lst);
t_list		*find_highest_node(t_list *lst);
t_list		*find_second_smallest_node(t_list *lsta);
char		*ft_strncpy(char *dest, const char *src, int size);
char		**ft_split(char *str);
char		*ft_strdup(char *str);
char		**ft_convert_format(int ac, char **av);
long long	str_conversion(char *str);

// Sorting.
void		handle_two_numbers(t_list **lsta);
void		sort_three_numbers(t_list **lsta);
void		sort_five_numbers(t_list **lsta, t_list **lstb);
void		sort_hundred(t_list **lsta, t_list **lstb);
void		sort_lst(t_list **lsta, t_list **lstb);
int			is_sorted(t_list *lsta);

// Radix
int			length_highest_index(t_list *lsta);
void		radix_sort_by_digit(t_list **lsta, t_list **lstb,
				int pos, int digit);

#endif
