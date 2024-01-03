/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:43:59 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/28 18:40:37 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *lst)
{
	size_t	length;

	length = 0;
	if (!lst || !lst->next)
		return (0);
	while (lst)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}

t_list	*lst_second_to_last(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst) || !(*lst)->next)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!(lst))
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = lst_last(*lst);
		last->next = new;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
