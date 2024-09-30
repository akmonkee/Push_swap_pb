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

void	sa(int *stack_a, int index)
{
	int	val;

	val = stack_a[index];
	stack_a[index] = stack_a[index + 1];
	stack_a[index + 1] = val;
}

void	sb(int *stack_b, int index)
{
	int	val;

	val = stack_b[index];
	stack_b[index] = stack_b[index + 1];
	stack_b[index + 1] = val;
}

void	ss(int *stack_a, int *stack_b, int index)
{
	sa(stack_a, index);
	sb(stack_b, index);
}

void	pa(int *stack_a, int *stack_b, t_index *t_index, int index)
{
	int	i;

	if (t_index->index_b == 0 || t_index->index_a == t_index->len)
		return ;
	i = t_index->index_a - 1;
	while (i >= 0)
	{
		sa(stack_a, i);
		i--;
	}
	stack_a[0] = stack_b[0];
	stack_b[0] = 0;
	t_index->index_a = t_index->index_a + 1;
	t_index->index_b = t_index->index_b - 1;
	while (index < t_index->index_b)
	{
		sb(stack_b, index);
		index++;
	}
}

void	pb(int *stack_a, int *stack_b, t_index *t_index, int index)
{
	int	i;

	if (t_index->index_a == 0 || t_index->index_b == t_index->len)
		return ;
	i = t_index->index_b - 1;
	while (i >= 0)
	{
		sb(stack_b, i);
		i--;
	}
	stack_b[0] = stack_a[0];
	stack_a[0] = 0;
	t_index->index_a = t_index->index_a - 1;
	t_index->index_b = t_index->index_b + 1;
	while (index < t_index->index_a)
	{
		sa(stack_a, index);
		index++;
	}
}
