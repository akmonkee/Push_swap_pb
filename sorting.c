/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:12:18 by msisto            #+#    #+#             */
/*   Updated: 2024/10/04 14:23:43 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b_3(int *stack_a, int *stack_b, t_index *t_index)
{
	int	i;
	int	k;

	while (t_index->index_a > 3 && !is_sorted(stack_a, t_index, 'a'))
	{
		k = 0;
		i = rotate_type_ab(stack_a, stack_b, t_index);
		while (i >= 0 && k < t_index->index_a)
		{
			if (i == case_rr(stack_a, stack_b, stack_a[k], t_index))
				i = ft_apply_rr_b(stack_a, stack_b, stack_a[k], t_index);
			else if (i == case_rrr(stack_a, stack_b, stack_a[k], t_index))
				i = ft_apply_rrarrb_b(stack_a, stack_b, stack_a[k], t_index);
			else if (i == case_rrarb(stack_a, stack_b, stack_a[k], t_index))
				i = ft_apply_rrarb_b(stack_a, stack_b, stack_a[k], t_index);
			else if (i == case_rarrb(stack_a, stack_b, stack_a[k], t_index))
				i = ft_apply_rarrb_b(stack_a, stack_b, stack_a[k], t_index);
			else
				k++;
		}
	}
}

void	sort_b(int *stack_a, int *stack_b, t_index *t_index)
{
	if (t_index->index_a > 3 && !is_sorted(stack_a, t_index, 'a'))
	{
		pb (stack_a, stack_b, t_index, 0);
		ft_printf("pb\n");
	}
	if (t_index->index_a > 3 && !is_sorted(stack_a, t_index, 'a'))
	{
		pb (stack_a, stack_b, t_index, 0);
		ft_printf("pb\n");
	}
	if (t_index->index_a > 3 && !is_sorted(stack_a, t_index, 'a'))
		sort_to_b_3(stack_a, stack_b, t_index);
	if (!is_sorted(stack_a, t_index, 'a'))
		return (sort_three(stack_a, t_index));
}

void	sort_a(int *stack_a, int *stack_b, t_index *t_index)
{
	int	i;
	int	k;

	k = 0;
	while (t_index->index_b > 0)
	{
		k = 0;
		i = rotate_type_ba(stack_a, stack_b, t_index);
		while (i >= 0 && t_index->index_b)
		{
			if (i == case_rr_a(stack_a, stack_b, stack_b[k], t_index))
				i = ft_apply_rr_a(stack_a, stack_b, stack_b[k], t_index);
			else if (i == case_rrr_a(stack_a, stack_b, stack_b[k], t_index))
				i = ft_apply_rrarrb_a(stack_a, stack_b, stack_b[k], t_index);
			else if (i == case_rrarb_a(stack_a, stack_b, stack_b[k], t_index))
				i = ft_apply_rrarb_a(stack_a, stack_b, stack_b[k], t_index);
			else if (i == case_rarrb_a(stack_a, stack_b, stack_b[k], t_index))
				i = ft_apply_rarrb_a(stack_a, stack_b, stack_b[k], t_index);
			else
				k++;
		}
	}
}

void	sorting(int *stack_a, int *stack_b, t_index *t_index)
{
	int	i;

	t_index->index_a = t_index->len;
	t_index->index_b = 0;
	if (t_index->index_a == 2 && !is_sorted(stack_a, t_index, 'a'))
	{
		sa(stack_a, 0);
		ft_printf("sa\n");
	}
	else if (!is_sorted(stack_a, t_index, 'a'))
	{
		sort_b(stack_a, stack_b, t_index);
		sort_a(stack_a, stack_b, t_index);
		min_nbr_top(stack_a, t_index);
	}
}
