/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:58:16 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/04 12:11:58 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int len_num(int nb)
{
	int count;

	count = 0;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 2;
		count++;
	}
	return (count);
}

// atoi > Pour convertir les arguments et refoutre dans une liste.
int ft_atoi(char *str)
{
	int i;
	int sign;
	long int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i + 1] == 43 || str[i + 1] == 45)
			return (0);
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		return (-1);
	return (sign * (int)result);
}
// => Check dans une autre fonction si atoi renvoie bien "-1" en tant que nb,
// ou s'il renvoie -1 en sortie d'erreur. Donc faire un strncmp.

int lst_size(t_list **lst)
{
	t_list *temp;
	int count;

	if (!(*lst) || !lst)
		return (0);
	temp = *lst;
	count = 0;
	while (temp)
	{
		count++; // Count avant ou apres ?
		temp = temp->next;
	}
	return (count);
}

int find_smallest(t_list **lst)
{
	int min;
	t_list *current;

	if (!(*lst) || !lst)
		return (0);
	current = *lst;
	min = current->content;
	while (current)
	{
		if (min > current->content)
			min = current->content;
		current = current->next;
	}
	return (min);
}

t_list *new_node(void *content)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list *lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void lst_add_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!(lst))
		return;
	if (!(*lst))
		*lst = new;
	else
	{
		last = lst_last(*lst);
		last->next = new;
	}
}

t_list *fill_lst(t_list **lst, int ac, char **av)
{
	int i;
	t_list *new;
	t_list *tmp;

	i = 1;
	tmp = *lst;
	while (ac > 1)
	{
		new = new_node(ft_atoi(av[i]));
		lst_add_back(lst, new);
		tmp = tmp->next;
		ac--;
		i++;
	}
	return (*lst);
}

mettre_en_haut(elem, pile)
	nbre_ra = count_ra(elem, pa)   // Combien de coups ra pour monter.
	nbre_rra = count_rra(elem, pa) // Cb de coups rra pour monter.
			   if nbrra
			   > nbbbb
			   while nbrera-- ra(pa) if n
			   while nbrera-- rra(pa)

				   algo_3_nbre(pa, pb)...

			   algo_simple(pa, pb)
			   // while(size(pa) > 0)
			   while (!est_trie(pa))
				   elem = find_smallest(pa)
				   mettre_en_haut(elem, pile)
					   pb() while (pile_size(b) > 0)
						   pa

// Nombre de tours pour le trie : nombre d'elements dans ta pile * le + grand nb
//  Trie : Les nb finissant par 1 dans la pile b et le reste pile a.
//  Tu mets ensuite la pile b dans la pile a (push vers le bas).
//  Si tu as 2/3 nombres, cas special qu'il faut gerer a la main.
//  Fonction qui regarde si la pile est triee.
//  Fonction qui cherche le plus grand dans la pile a, l'envoie en haut et le switch dans pile b.

// WARNING : Gerer si UN ARG. contient tous les nbs avec un esp. entre chq.
// => FAIRE SPLIT ET COUNTWORDS.

#include <stdio.h>

	int main()
{
	printf("%d\n", len_num(0));
	return (0);
}
