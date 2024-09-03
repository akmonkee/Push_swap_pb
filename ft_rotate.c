/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:49:03 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 11:47:43 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ab(int	*stack_a, int *stack_b, int len)
{
	int	i;
	int	k;

	k = 0;
	i = case_rrr(stack_a, stack_b, stack_a[0], len);
	while (k < len)
	{
		if (i > case_rr(stack_a, stack_b, stack_a[k], len))
			i = case_rr(stack_a, stack_b, stack_a[k], len);
		if (i > case_rrr(stack_a, stack_b, stack_a[k], len))
			i = case_rrr(stack_a, stack_b, stack_a[k], len);
		if (i > case_rarrb(stack_a, stack_b, stack_a[k], len))
			i = case_rarrb(stack_a, stack_b, stack_a[k], len);
		if (i > case_rrarb(stack_a, stack_b, stack_a[k], len))
			i = case_rrarb(stack_a, stack_b, stack_a[k], len);
		k++;
	}
	return (i);
}

int	rotate_type_ba(int	*stack_a, int *stack_b, int len)
{
	int	i;
	int	k;

	k = 0;
	i = case_rrr(stack_a, stack_b, stack_a[0], len);
	while (k < len)
	{
		if (i > case_rr_a(stack_a, stack_b, stack_a[k], len))
			i = case_rr_a(stack_a, stack_b, stack_a[k], len);
		if (i > case_rrr_a(stack_a, stack_b, stack_a[k], len))
			i = case_rrr_a(stack_a, stack_b, stack_a[k], len);
		if (i > case_rarrb_a(stack_a, stack_b, stack_a[k], len))
			i = case_rarrb_a(stack_a, stack_b, stack_a[k], len);
		if (i > case_rrarb_a(stack_a, stack_b, stack_a[k], len))
			i = case_rrarb_a(stack_a, stack_b, stack_a[k], len);
		k++;
	}
	return (i);
}
