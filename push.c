/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:03 by jeguerin          #+#    #+#             */
/*   Updated: 2023/11/22 15:55:26 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_a(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lstb))
		return ;
	write(1, "pa\n", 3);
	temp = (*lstb);
	(*lstb) = (*lstb)->next;
	temp->next = (*lsta);
	(*lsta) = temp;
}
// Faut-il que le node de b quand il est envoye sur a,
// prenne la premiere place et donc qu'on update *lsta ? OUI
// Il faut : update le node envoye dans a en premier node (donc 1er node
// devient le 2eme).
// Il faut aussi update b, en mettant le deuxieme node en premier.

void	push_b(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lsta))
		return ;
	write(1, "pb\n", 3);
	temp = (*lsta);
	(*lsta) = (*lsta)->next;
	temp->next = (*lstb);
	(*lstb) = temp;
}
