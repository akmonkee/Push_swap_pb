/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:07:36 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 12:40:59 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int len, int index)
{
	int	val;

	val = stack_a[index];
	stack_a[index] = stack_a[index + 1];
	stack_a[index + 1] = val;
}

void	sb(int *stack_b, int len, int index)
{
	int	val;

	val = stack_b[index];
	stack_b[index] = stack_b[index + 1];
	stack_b[index + 1] = val;
}

void	ss(int *stack_a, int *stack_b, int len, int index)
{
	sa(stack_a, len, index);
	sb(stack_b, len, index);
}

void	pa(int *stack_a, int *stack_b, int len, int index)
{
	int	i;

	i = len - 1;
	if (!stack_b)
		return ;
	while (--i >= 0)
	{
		if (stack_a[i] != 0)
			sa(stack_a, len, i);
	}
	stack_a[0] = stack_b[0];
	stack_b[0] = '\0';
	while (index < len)
	{
		sb(stack_b, len, index);
		index++;
	}
}

void	pb(int *stack_a, int *stack_b, int len, int index)
{
	int	i;

	i = len - 1;
	if (!stack_a)
		return ;
	while (--i >= 0)
	{
		if (stack_b[i] != 0)
			sb(stack_b, len, i);
	}
	stack_b[0] = stack_a[0];
	stack_a[0] = '\0';
	while (index < len)
	{
		sa(stack_a, len, index);
		index++;
	}
}
