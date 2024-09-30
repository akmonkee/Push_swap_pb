/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_moves1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:53:52 by msisto            #+#    #+#             */
/*   Updated: 2024/09/30 11:13:18 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_b[0] != nbr
		&& find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		rr(stack_a, stack_b, t_index, 0);
		ft_printf("rr\n");
	}
	while (stack_b[0] != nbr)
	{
		rb(stack_b, t_index, 0);
		ft_printf("rb\n");
	}
	while (find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		ra(stack_a, t_index, 0);
		ft_printf("ra\n");
	}
	pa(stack_a, stack_b, t_index, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rrarrb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_b[0] != nbr
		&& find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		rrr(stack_a, stack_b, t_index, 0);
		ft_printf("rrr\n");
	}
	while (stack_b[0] != nbr)
	{
		rrb(stack_b, t_index, 0);
		ft_printf("rrb\n");
	}
	while (find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		rra(stack_a, t_index, 0);
		ft_printf("rra\n");
	}
	pa(stack_a, stack_b, t_index, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rrarb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_b[0] != nbr)
	{
		rb(stack_b, t_index, 0);
		ft_printf("rb\n");
	}
	while (find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		rra(stack_a, t_index, 0);
		ft_printf("rra\n");
	}
	pa(stack_a, stack_b, t_index, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rarrb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	while (stack_b[0] != nbr)
	{
		rrb(stack_b, t_index, 0);
		ft_printf("rrb\n");
	}
	while (find_placein_a(stack_a, nbr, t_index->index_a) > 0)
	{
		ra(stack_a, t_index, 0);
		ft_printf("ra\n");
	}
	pa(stack_a, stack_b, t_index, 0);
	ft_printf("pa\n");
	return (-1);
}
