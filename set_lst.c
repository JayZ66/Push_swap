/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:23:02 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/26 16:13:49 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

t_list	*find_smallest_index(t_list **lst)
{
	t_list	*min; // Noeud qui stocke le plus petit nb actuel de la liste.
	t_list	*tmp_lst; // Clone liste pour iterer dedans.

	if (!(*lst))
		return (NULL);
	min = *lst;
	tmp_lst = (*lst)->next;
	while (tmp_lst)
	{
		if (tmp_lst->index < min->index)
			min = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return (min);
}

t_list	*find_smallest_one(t_list **lst)
{
	t_list	*min; // Noeud qui stocke le plus petit nb actuel de la liste.
	t_list	*tmp_lst; // Clone liste pour iterer dedans.

	min = NULL;
	tmp_lst = *lst;
	while(tmp_lst)
	{
		if (tmp_lst->index == -1 && (min == NULL
			|| tmp_lst->content < min->content))
			min = tmp_lst;
		tmp_lst = tmp_lst->next;
	}
	return(min);
}

void	define_list_index(t_list **lst)
{
	t_list			*min;
	unsigned long int	index;

	index = 0;
	while(1)
	{
		min = find_smallest_one(lst);
		if (min == NULL)
			return ;
		min->index = index;
		index++;
	}
}
// The aim of this function is to check if there are duplicates in the list.
// If so, we have to free the list and stop the process.

int	check_doublons(t_list *lst)
{
	t_list	*current; //To iterate on lst.
	t_list	*next_node; // To check the next node.
	int		doubles; //To save if doubles are in the list.

	current = lst;
	doubles = 0;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (next_node->content == current->content) // To compare two numbers.
				doubles = 1;
			next_node = next_node->next;
		}
		current = current->next;
	}
	if (doubles == 1)
	{
		del_nodes(&lst);
		write(1, "Duplicates in the list\n", 23);
		return (-1); //Allow to end the program with a return code.
	}
	return (0);
}


t_list *new_node(int content)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = -1;
	lst->next = NULL;
	return (lst);
}

//convert_format
char	**ft_convert_format(int ac, char **av)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!result)
		return (NULL);
	result[ac - 1] = NULL;
	while (i < ac - 1)
	{
		result[i] = ft_strdup(av[i + 1]);
		if (!result)
			return (ft_free_array(result), NULL);
		i++;
	}
	return (result);
}


t_list *fill_lst(t_list **lst, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		num;

	i = 0;
	while (ac > 1)
	{
		num = ft_atoi(av[i]);
		if (num == -1)
			return (ft_free_array(av), del_nodes(lst), NULL);
		new = new_node(num);
		lst_add_back(lst, new);
		ac--;
		i++;
	}
	if (check_doublons(*lst) == -1)
		return (ft_free_array(av), NULL);
	define_list_index(lst);
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (*lst);
}

// while(tmp_lst) // Tant qu'on est dans la liste.
// 	{
// 		if (tmp_lst->index == -1 && (min == NULL
// 			|| tmp_lst->content < min->content))
// // Si l'index est egal a -1, c'est que le content (nb) a pas ete trie et indexe.
// // Et si min == NULL, donc ne contient pas encore le content (nb) le + petit.
// // Ou si min contient un nb, et que le contenu (nb) du noeud est inferieur
// // au nb contenu dans le node min.
// 			min = tmp_lst; // Min prend la valeur de la liste tmp (+ petite val)
// 		tmp_lst = tmp_lst->next; // On passe au noeud suivant.
// 	}
// 	// On fait ca pour toute la liste, et a chq fois min recup. la + petite val.
