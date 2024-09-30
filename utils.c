/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:18 by msisto            #+#    #+#             */
/*   Updated: 2024/06/17 11:33:38 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_of_stack(int *stack, int len)
{
	int	i;
	int	max;

	i = 0;
	max = stack[i];
	while (i < len)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	min_of_stack(int *stack, int len)
{
	int	i;
	int	min;

	i = 0;
	min = stack[i];
	while (i < len)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	last_finder(int *stack, int len)
{
	int	i;

	i = 0;
	if (!stack)
		return ('\0');
	while (i < len)
		i++;
	return (stack[i]);
}

int	stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\0')
		i++;
	return (i);
}
