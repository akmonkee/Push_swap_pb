/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:16:23 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 12:37:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_placein_b(int *stack, int nbr, int len)
{
	int	i;

	i = 1;
	if (nbr > stack[0] && nbr < last_finder(stack, len - 1))
		return (0);
	else if (nbr > max_of_stack(stack, len) || nbr < min_of_stack(stack, len))
		return (index_finder(stack, max_of_stack(stack, len), len));
	else
	{
		while (i < len && (stack[i] < nbr || stack[i + 1] > nbr))
			i++;
	}
	return (i);
}

int	find_placein_a(int *stack, int nbr, int len)
{
	int	i;

	i = 1;
	if (nbr < stack[0] && nbr > last_finder(stack, len - 1))
		i = 0;
	else if (nbr < min_of_stack(stack, len) || nbr > max_of_stack(stack, len))
		return (index_finder(stack, min_of_stack(stack, len), len));
	else
	{
		while (i < len && (stack[i] > nbr || stack[i + 1] < nbr))
			i++;
	}
	return (i);
}

int	is_sorted(int *stack, t_index *t_index, char type)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = stack[0];
	if (type == 'a')
	{
		while (++i < t_index->index_a)
		{
			if (nbr > stack[i])
				return (0);
			nbr = stack[i];
		}
	}
	else
	{
		while (++i < t_index->index_b)
		{
			if (nbr < stack[i])
				return (0);
			nbr = stack[i];
		}
	}
	return (1);
}

int	index_finder(int *stack, int nbr, int len)
{
	int	i;

	i = 0;
	while (stack[i] != nbr && i <= len)
		i++;
	return (i);
}
