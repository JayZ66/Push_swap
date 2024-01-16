/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:40:01 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 12:01:24 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;
	int		size;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list	*find_smallest_nb(t_list **lst)
{
	t_list	*min;
	t_list	*tmp_lst;

	min = NULL;
	tmp_lst = *lst;
	while (tmp_lst)
	{
		if (tmp_lst->index == -1 && (min == NULL
				|| tmp_lst->content < min->content))
			min = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return (min);
}

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i + 1);
}

t_list	*find_smallest_node(t_list *lst)
{
	int		min_node;
	t_list	*smallest_node;

	if (!lst)
		return (NULL);
	min_node = INT_MAX;
	smallest_node = NULL;
	while (lst)
	{
		if (lst->content < min_node)
		{
			min_node = lst->content;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}

t_list	*find_second_smallest_node(t_list *lsta)
{
	t_list	*first_smallest_node;
	int		second_smallest_value;
	t_list	*second_smallest_node;
	t_list	*tmp;

	first_smallest_node = find_smallest_node(lsta);
	second_smallest_value = INT_MAX;
	second_smallest_node = NULL;
	tmp = lsta;
	while (tmp)
	{
		if ((tmp != first_smallest_node)
			&& (tmp->content < second_smallest_value))
		{
			second_smallest_value = tmp->content;
			second_smallest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (second_smallest_node);
}
