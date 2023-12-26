/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:39:39 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/22 11:01:47 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length_highest_index(t_list *lsta)
{
	int		count;
	int		highest_nb;
	t_list	*highest_node;

	if (!lsta)
		return (0);
	count = 0;
	highest_node = find_highest_node(lsta);
	highest_nb = highest_node->index;
	if (highest_nb == 0)
		return (0);
	while (highest_nb != 0)
	{
		highest_nb /= 10;
		count++;
	}
	return (count);
}

// Return the max. number of mooves to sort the stack.

int	is_sorted(t_list *lsta)
{
	t_list	*temp;
	if (!lsta)
		return (-1);
	temp = lsta;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	radix_sort_by_digit(t_list **lsta, t_list **lstb, int position, int digit)
{
	int	i;
	int	list_size;
	int	current_index;
	int	current_position;

	i = 0;
	list_size = lst_size(*lsta);
	while (i < list_size)
	{
		current_index = (*lsta)->index;
		current_position = position;
		while (current_position != 0)
		{
			current_index /= 10;
			current_position--;
		}
		if ((current_index % 10) == digit)
			push_b(lsta, lstb);
		else
			rotate_a(lsta, 1);
		i++;
	}
}

/*
Radix :
Nb de rounds = unites de l'index max.
digit = 9 (9 a 0 pour chq unite)
Position (incrementer pour check le nb de rounds)
Tant que position est inf. a rounds. (Pos. = 0 > Unites)
d = 9;
tant que digit >=0
	> Fonction check digit to push b or not. (lsta, lstb, position, digit).
		digit++;
On ramene tout dans la pile a.
position++;
*/

void	sort_hundred(t_list** lsta, t_list** lstb)
{
	int	rounds;
	int	digit;
	int	position;

	rounds = length_highest_index(*lsta);
	position = 0;
	while (position < rounds)
	{
		digit = 0;
		while (digit <= 9)
		{
			radix_sort_by_digit(lsta, lstb, position, digit);
			digit++;
		}
		while (*lstb)
			push_a(lsta, lstb);
		position++;
	}
}


// Do fonction : Check les doublons dans la liste sent.
// Fonction qui check si nb en doublons => Integrer dans fill_lst. + index.
// Puis mettre a la fin (une fois que lst est fill) les indexs.

// Check also si nb sont pas un int !
// Integrer les free > Memory leaks.
// Fonction format qui convertit les args.
// Faire fonction qui convertit les args. en int.



/*
En gros : On part de la "box" 9 jusqu'a 0 donc l'unite du nb.
Si c'est 9 alors on met dans la pile b, sinon on rotate.
On passe a 8, on recommence dans la pile a.
Et ainsi de suite, jusqu'a que la pile a soit vide.
Une fois ca on passe aux dizaines depuis la pile b.
Puis on renvoie tout dans la pile a ? A voir.
*/


/*
Sort :
- Take 3 median numbers in lsta and push them in lstb.
- Then compare each number of lsta with the 3 numbers in lstb to sort them.
*/
