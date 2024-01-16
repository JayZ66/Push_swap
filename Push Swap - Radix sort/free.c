/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:02:11 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/29 09:26:27 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_nodes(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (*lst)
	{
		*lst = temp->next;
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}
