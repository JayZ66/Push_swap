/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:49 by jeguerin          #+#    #+#             */
/*   Updated: 2023/12/22 08:55:17 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (!(str[i] == ' ' || str[i] == '\n' || str[i]== '\t'))
			count++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**new;
	int		i;
	int		word;
	int		j;

	i = 0;
	word = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!new)
		return (NULL); // No need to free, bcse if it failed, there's no malloc.
	while (str[i])
	{
		while (str[i] && str[i]
			&& (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && !(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (j < i)
		{
			new[word] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!new[word])
			{
				while (word >= 0)
				{
					free(new[word]);
					word--;
				}
				free(new);
				return (NULL);
			}
			ft_strncpy(new[word], &str[j], i - j);
			word++;
		}
	}
	new[word] = NULL;
	return (new);
}
