/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:53:17 by jeguerin          #+#    #+#             */
/*   Updated: 2024/01/16 14:39:16 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}	t_list;

typedef struct s_data
{
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}		t_data;

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
int			ft_atoi_ps(char *str);
int			lst_size(t_list **lst);
int			count_words(char *str);
int			ft_strlen_ps(char *str);
int			check_doublons(t_list *lst);
int			check_is_digit(const char *str);
int			check_digit_size(long long digit);
int			array_len(char **arr);
int			find_highest_nb(t_list *lst);
int			find_highest_index(t_list *lst, int max);
int			*sort_array(t_list *lst);
void		bubble_sort(int *arr, int arr_len);
void		lst_add_back(t_list **lst, t_list *new);
void		push_smallests_at_the_bottom(t_list	**lsta);
void		del_nodes(t_list **lst);
void		ft_free_array(char **arr);
void		check_string(char **new, char *str);
t_list		*new_node(int content);
t_list		*lst_last(t_list *lst);
t_list		*fill_lst(t_list **lst, int ac, char **av);
t_list		*lst_second_to_last(t_list **lst);
t_list		*find_smallest_node(t_list *lst);
t_list		*find_highest_node(t_list *lst);
t_list		*find_second_smallest_node(t_list *lsta);
char		*ft_strncpy(char *dest, const char *src, int size);
char		**ft_split_ps(char *str);
char		*ft_strdup_ps(char *str);
char		**ft_convert_format(int ac, char **av);
long long	str_conversion(char *str);

// Sorting.
void		sort_two_numbers(t_list **lsta);
void		sort_three_numbers(t_list **lsta);
void		sort_five_numbers(t_list **lsta, t_list **lstb);
void		sort_lst(t_list **lsta, t_list **lstb, int *array, t_data *data);
int			is_sorted(t_list *lsta, t_list *lstb);
void		sort_stack_a_to_b(t_list **lsta, t_list **lstb, int *array,
				t_data *data);
void		sort_stack_b_to_a(t_list **lsta, t_list **lstb, int *array,
				t_data *data);
void		check_highest_nb(t_list **lsta, t_list **lstb, int *array,
				t_data *data);
void		check_unsorted_nb(t_list **lsta, t_data *data);
void		check_not_max_num(t_list **lsta, t_list **lstb, t_data *data);

// Bonus - Instructions
void		bonus_pa(t_list **lsta, t_list **lstb);
void		bonus_pb(t_list **lsta, t_list **lstb);
void		bonus_rrr(t_list **lsta, t_list **lstb);
void		bonus_ss(t_list **lsta, t_list **lstb);
void		bonus_rr(t_list **lstb, t_list **lsta);

// Bonus - Checker
int			ft_strcmp(const char *s1, const char *s2);
int			is_sorted(t_list *lsta, t_list *lstb);
void		check_instructions(char *str, t_list **lsta, t_list **lstb);
void		check_final_stack(t_list **lsta, t_list **lstb, int i, char *str);

// Bonus - GNL
int			ft_strlen_gnl(char *str);
int			ft_strchr_gnl(const char *str, int c);
char		*ft_strndup(const char *str, int size);
char		*ft_join(char *s1, char *s2);
char		*update_stash(char *stash);
char		*extract_line(char *stash);
char		*get_next_line(int fd);

#endif
