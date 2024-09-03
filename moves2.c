/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:40:41 by msisto            #+#    #+#             */
/*   Updated: 2024/06/06 11:08:42 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *stack_a, int len, int index)
{
	while (index < len - 1)
	{
		if (stack_a[index + 1] != 0)
			sa(stack_a, len, index);
		index++;
	}
}

void	rb(int *stack_b, int len, int index)
{
	while (index < len - 1)
	{
		if (stack_b[index + 1] != 0)
			sb(stack_b, len, index);
		index++;
	}
}

void	rr(int *stack_a, int *stack_b, int len, int index)
{
	ra(stack_a, len, index);
	rb(stack_b, len, index);
}

void	rra(int *stack_a, int len, int index)
{
	index = len - 1;
	while (--index >= 0)
		if (stack_a[index + 1] != 0)
			sa(stack_a, len, index);
}

void	rrb(int *stack_b, int len, int index)
{
	index = len - 1;
	while (--index >= 0)
		if (stack_b[index + 1] != 0)
			sb(stack_b, len, index);
}
