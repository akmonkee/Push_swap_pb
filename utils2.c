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
	if (nbr > stack[0] && nbr < last_finder(stack, len))
		i = 0;
	else if (nbr > max_of_stack(stack, len))
		i = index_finder(stack, max_of_stack(stack, len), len);
	else if (nbr < min_of_stack(stack, len))
		i = index_finder(stack, min_of_stack(stack, len), len);
	else
	{
		while ((stack[i] < nbr || stack[i + 1] > nbr) && i < len - 1)
			i++;
	}
	return (i);
}

int	find_placein_a(int *stack, int nbr, int len)
{
	int	i;

	i = 1;
	if (nbr < stack[0] && nbr > last_finder(stack, len))
		i = 0;
	else if (nbr > max_of_stack(stack, len))
		i = index_finder(stack, max_of_stack(stack, len), len);
	else if (nbr < min_of_stack(stack, len))
		i = index_finder(stack, min_of_stack(stack, len), len);
	else
	{
		while ((stack[i] > nbr || stack[i + 1] < nbr) && i < len - 1)
			i++;
	}
	return (i);
}

int	is_sorted(int *stack, int len, char type)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = stack[0];
	if (type == 'a')
	{
		while (++i < len)
		{
			if (nbr > stack[i])
				return (0);
			nbr = stack[i];
		}
	}
	else
	{
		while (++i < len)
		{
			if (nbr < stack[i])
				return (0);
			nbr = stack[i];
		}
	}
	return (1);
}
