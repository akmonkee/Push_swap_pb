/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:02:06 by msisto            #+#    #+#             */
/*   Updated: 2024/06/18 11:14:48 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rr_b(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_a[0] != nbr && find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rr(stack_a, stack_b, t_index, 0);
		ft_printf("rr\n");
	}
	while (stack_a[0] != nbr)
	{
		ra(stack_a, t_index, 0);
		ft_printf("ra\n");
	}
	while (find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rb(stack_b, t_index, 0);
		ft_printf("rb\n");
	}
	pb(stack_a, stack_b, t_index, 0);
	ft_printf("pb\n");
	return (-1);
}

int	ft_apply_rrarrb_b(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_a[0] != nbr && find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rrr(stack_a, stack_b, t_index, 0);
		ft_printf("rrr\n");
	}
	while (stack_a[0] != nbr)
	{
		rra(stack_a, t_index, 0);
		ft_printf("rra\n");
	}
	while (find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rrb(stack_b, t_index, 0);
		ft_printf("rrb\n");
	}
	pb(stack_a, stack_b, t_index, 0);
	ft_printf("pb\n");
	return (-1);
}

int	ft_apply_rrarb_b(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_a[0] != nbr)
	{
		rra(stack_a, t_index, 0);
		ft_printf("rra\n");
	}
	while (find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rb(stack_b, t_index, 0);
		ft_printf("rb\n");
	}
	pb(stack_a, stack_b, t_index, 0);
	ft_printf("pb\n");
	return (-1);
}

int	ft_apply_rarrb_b(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_a[0] != nbr)
	{
		ra(stack_a, t_index, 0);
		ft_printf("ra\n");
	}
	while (find_placein_b(stack_b, nbr, t_index->index_b) > 0)
	{
		rrb(stack_b, t_index, 0);
		ft_printf("rrb\n");
	}
	pb(stack_a, stack_b, t_index, 0);
	ft_printf("pb\n");
	return (-1);
}
