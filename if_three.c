/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:05:31 by msisto            #+#    #+#             */
/*   Updated: 2024/09/30 11:34:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_util(int	*stack, t_index *t_index)
{
	if (index_finder(stack,
			max_of_stack(stack, t_index->index_a), t_index->index_a)
		== 1 && !is_sorted(stack, t_index, 'a'))
	{
		rra(stack, t_index, 0);
		ft_printf("rra\n");
	}
	else if (!is_sorted(stack, t_index, 'a'))
	{
		sa(stack, 0);
		ft_printf("sa\n");
	}
}

void	sort_three(int	*stack, t_index *t_index)
{
	if (min_of_stack(stack, t_index->index_a)
		== stack[0] && !is_sorted(stack, t_index, 'a'))
	{
		rra(stack, t_index, 0);
		ft_printf("rra\n");
		sa(stack, 0);
		ft_printf("sa\n");
	}
	else if (max_of_stack(stack, t_index->index_a) == stack[0]
		&& !is_sorted(stack, t_index, 'a'))
	{
		ra(stack, t_index, 0);
		ft_printf("ra\n");
		if (!is_sorted(stack, t_index, 'a'))
		{
			sa(stack, 0);
			ft_printf("sa\n");
		}
	}
	else
		sort_three_util(stack, t_index);
}
