/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:05:31 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 14:47:26 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int	*stack, int len)
{
	if (min_of_stack(stack, len) == stack[0])
	{
		rra(stack, len, 0);
		ft_printf("rra\n");
		sa(stack, len, 0);
		ft_printf("sa\n");
	}
	else if (max_of_stack(stack, len) == stack[0])
	{
		ra(stack, len, 0);
		ft_printf("ra\n");
		if (!is_sorted(stack, len, 'a'))
		{
			sa(stack, len, 0);
			ft_printf("sa\n");
		}
	}
	else
	{
		if (index_finder(stack, max_of_stack(stack, len), len) == 1)
		{
			rra(stack, len, 0);
			ft_printf("rra\n");
		}
		else
		{
			sa(stack, len, 0);
			ft_printf("sa\n");
		}
	}
}
