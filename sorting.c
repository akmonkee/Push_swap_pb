/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:12:18 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 14:45:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b_3(int *stack_a, int *stack_b, int len)
{
	int	i;
	int	k;

	while (stack_size(stack_a) > 3 && !is_sorted(stack_a, len, 'a'))
	{
		k = 0;
		i = rotate_type_ab(stack_a, stack_b, len);
		while (i >= 0)
		{
			if (i == case_rr(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rr_b(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rrr(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rrarrb_b(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rrarb(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rrarb_b(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rarrb(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rarrb_b(stack_a, stack_b, stack_a[k], len);
			else
				k++;
		}
	}
}

void	sort_b(int *stack_a, int *stack_b, int len)
{
	if (stack_size(stack_a) > 3 && !is_sorted(stack_a, len, 'a'))
	{
		pb (stack_a, stack_b, len, 0);
		ft_printf("pb\n");
	}
	if (stack_size(stack_a) > 3 && !is_sorted(stack_a, len, 'a'))
	{
		pb (stack_a, stack_b, len, 0);
		ft_printf("pb\n");
	}
	if (stack_size(stack_a) > 3 && !is_sorted(stack_a, len, 'a'))
		sort_to_b_3(stack_a, stack_b, len);
	if (!is_sorted(stack_a, len, 'a') && len == 3)
		return (sort_three(stack_a, len));
}

void	sort_a(int *stack_a, int *stack_b, int len)
{
	int	i;
	int	k;

	k = 0;
	while (k < len)
	{
		k = 0;
		i = rotate_type_ba(stack_a, stack_b, len);
		while (i >= 0)
		{
			if (i == case_rr_a(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rr_a(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rrr_a(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rrarrb_a(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rrarb_a(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rrarb_a(stack_a, stack_b, stack_a[k], len);
			else if (i == case_rarrb_a(stack_a, stack_b, stack_a[k], len))
				i = ft_apply_rarrb_a(stack_a, stack_b, stack_a[k], len);
			else
				k++;
		}
	}
}

void	sorting(int *stack_a, int *stack_b, int len)
{
	int	i;

	if (len == 2 && !is_sorted(stack_a, len, 'a'))
	{
		sa(stack_a, len, 0);
		ft_printf("sa\n");
	}
	else if (!is_sorted(stack_a, len, 'a'))
	{
		sort_b(stack_a, stack_b, len);
		sort_a(stack_a, stack_b, len);
		i = index_finder(stack_a, min_of_stack(stack_a, len), len);
		if (i < stack_size(stack_a) - i)
		{
			while (stack_a[0] != min_of_stack(stack_a, len))
				ra(stack_a, len, 0);
		}
		else
		{
			while (stack_a[0] != min_of_stack(stack_a, len))
				rra(stack_a, len, 0);
		}
	}
	print_stack(stack_a, len);
	print_stack(stack_b, len);
}
