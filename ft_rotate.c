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

int	rotate_type_ab(int	*stack_a, int *stack_b, t_index *t_index)
{
	int	i;
	int	k;

	k = 0;
	i = case_rrr(stack_a, stack_b, stack_a[k], t_index);
	while (k < t_index->index_a)
	{
		if (i > case_rr(stack_a, stack_b, stack_a[k], t_index))
			i = case_rr(stack_a, stack_b, stack_a[k], t_index);
		if (i > case_rrr(stack_a, stack_b, stack_a[k], t_index))
			i = case_rrr(stack_a, stack_b, stack_a[k], t_index);
		if (i > case_rarrb(stack_a, stack_b, stack_a[k], t_index))
			i = case_rarrb(stack_a, stack_b, stack_a[k], t_index);
		if (i > case_rrarb(stack_a, stack_b, stack_a[k], t_index))
			i = case_rrarb(stack_a, stack_b, stack_a[k], t_index);
		else
		k++;
		//ft_printf("case_rr: %d\n", case_rr(stack_a, stack_b, stack_a[k - 1], t_index));
		//ft_printf("case_rrr: %d\n", case_rrr(stack_a, stack_b, stack_a[k - 1], t_index));
		//ft_printf("case_rrarb: %d\n", case_rrarb(stack_a, stack_b, stack_a[k - 1], t_index));
		//ft_printf("case_rarrb: %d\n", case_rarrb(stack_a, stack_b, stack_a[k - 1], t_index));
		//ft_printf("nbr: %d\n", stack_a[k - 1]);
		//ft_printf("k: %d\n", k - 1);
		//ft_printf("-----------------------\n");
	}
	return (i);
}

int	rotate_type_ba(int	*stack_a, int *stack_b, t_index *t_index)
{
	int	i;
	int	k;

	k = 0;
	i = case_rrr_a(stack_a, stack_b, stack_b[0], t_index);
	while (k < t_index->index_b)
	{
		if (i > case_rr_a(stack_a, stack_b, stack_b[k], t_index))
			i = case_rr_a(stack_a, stack_b, stack_b[k], t_index);
		if (i > case_rrr_a(stack_a, stack_b, stack_b[k], t_index))
			i = case_rrr_a(stack_a, stack_b, stack_b[k], t_index);
		if (i > case_rarrb_a(stack_a, stack_b, stack_b[k], t_index))
			i = case_rarrb_a(stack_a, stack_b, stack_b[k], t_index);
		if (i > case_rrarb_a(stack_a, stack_b, stack_b[k], t_index))
			i = case_rrarb_a(stack_a, stack_b, stack_b[k], t_index);
		else
			k++;
		//ft_printf("case_rr_a: %d\n", case_rr_a(stack_a, stack_b, stack_b[k - 1], t_index));
		//ft_printf("case_rrr_a: %d\n", case_rrr_a(stack_a, stack_b, stack_b[k - 1], t_index));
		//ft_printf("case_rrarb_a: %d\n", case_rrarb_a(stack_a, stack_b, stack_b[k - 1], t_index));
		//ft_printf("case_rarrb_a: %d\n", case_rarrb_a(stack_a, stack_b, stack_b[k - 1], t_index));
		//ft_printf("nbr: %d\n", stack_b[k - 1]);
		//ft_printf("k:%d\n", k - 1);
		//ft_printf("-----------------------\n");
	}
	return (i);
}
