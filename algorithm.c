/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:58:16 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/26 13:41:57 by jeguerin         ###   ########.fr       */
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

int	check_is_digit(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[0] == '-' && str[1] >= '0' && str[1] <= '9')))
			return (-1);
		i++;
	}
	return (0);
}

int	check_digit_size(long long digit)
{
	if (digit > INT_MAX || digit < INT_MIN)
		return (-1);
	return (0);
}

// atoi > Pour convertir les arguments et refoutre dans une liste.
int ft_atoi(char *str)
{
	int	i;
	int	sign;
	long long	result;
	int	digit;
	long long	digit_size;

	i = 0;
	sign = 1;
	result = 0;
	digit = check_is_digit(str);
	if (digit == -1)
	{
		write(1, "This is not a digit\n", 20);
		return (-1);
	}
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
	digit_size = check_digit_size(result * sign);
	if (digit_size == -1)
	{
		write(1, "Digit size is not good\n", 23);
		return (-1);
	}
	return (sign * (int)result);
}
// => Check dans une autre fonction si atoi renvoie bien "-1" en tant que nb,
// ou s'il renvoie -1 en sortie d'erreur. Donc faire un strncmp.

// int lst_size(t_list **lst)
// {
// 	t_list *temp;
// 	int count;

// 	if (!(*lst) || !lst)
// 		return (0);
// 	temp = *lst;
// 	count = 0;
// 	while (temp)
// 	{
// 		count++; // Count avant ou apres ?
// 		temp = temp->next;
// 	}
// 	return (count);
// }

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
