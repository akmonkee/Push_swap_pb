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

void	ra(int *stack_a, t_index *t_index, int index)
{
	while (index < t_index->index_a - 1)
	{
		sa(stack_a, index);
		index++;
	}
}

void	rb(int *stack_b, t_index *t_index, int index)
{
	while (index < t_index->index_b - 1)
	{
		sb(stack_b, index);
		index++;
	}
}

void	rr(int *stack_a, int *stack_b, t_index *t_index, int index)
{
	ra(stack_a, t_index, index);
	rb(stack_b, t_index, index);
}

void	rra(int *stack_a, t_index *t_index, int index)
{
	index = t_index->index_a - 1;
	while (--index >= 0)
		sa(stack_a, index);
}

void	rrb(int *stack_b, t_index *t_index, int index)
{
	index = t_index->index_b - 1;
	while (--index >= 0)
		sb(stack_b, index);
}
