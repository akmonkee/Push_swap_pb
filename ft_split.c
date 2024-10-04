/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:05 by msisto            #+#    #+#             */
/*   Updated: 2024/09/30 15:25:07 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			spaces++;
	}
	if (str[0] == c || str[i] == c)
		return (spaces);
	else if (str[0] == c && str[i] == c)
		return (spaces - 1);
	else
		return (spaces + 1);
}

void	new_string(const char *str, int start, int end, char *dest)
{
	int	i;

	i = 0;
	while (i < end)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
}

void	aux(char **arr, const char *str, char c)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (str[i] && z <= count_words(str, c))
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			arr[z] = (char *)malloc(sizeof(char) * (j + 1));
			if (!arr[z])
				return ;
			new_string(str, i, j, arr[z]);
			z++;
			i += j;
		}
	}
}

char	**ft_split(const char *str, char c)
{
	char	**arr;
	int		n_words;

	if (!str)
		return (NULL);
	n_words = count_words(str, c);
	arr = malloc((n_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	aux(arr, str, c);
	arr[n_words] = NULL;
	return (arr);
}
