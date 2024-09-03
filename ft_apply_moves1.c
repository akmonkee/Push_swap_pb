/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_moves1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:53:52 by msisto            #+#    #+#             */
/*   Updated: 2024/06/18 11:15:21 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rr_a(int *stack_a, int *stack_b, int nbr, int len)
{
	while (stack_b[0] != nbr && find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rr\n");
		rr(stack_a, stack_b, len, 0);
	}
	while (stack_b[0] != nbr)
	{
		ft_printf("ra\n");
		ra(stack_a, len, 0);
	}
	while (find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rb\n");
		rb(stack_b, len, 0);
	}
	pa(stack_a, stack_b, len, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rrarrb_a(int *stack_a, int *stack_b, int nbr, int len)
{
	while (stack_b[0] != nbr && find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rrr\n");
		rrr(stack_a, stack_b, len, 0);
	}
	while (stack_b[0] != nbr)
	{
		ft_printf("rra\n");
		rra(stack_a, len, 0);
	}
	while (find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rrb\n");
		rrb(stack_b, len, 0);
	}
	pa(stack_a, stack_b, len, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rrarb_a(int *stack_a, int *stack_b, int nbr, int len)
{
	while (stack_b[0] != nbr)
	{
		ft_printf("rra\n");
		rra(stack_a, len, 0);
	}
	while (find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rb\n");
		rb(stack_b, len, 0);
	}
	pa(stack_a, stack_b, len, 0);
	ft_printf("pa\n");
	return (-1);
}

int	ft_apply_rarrb_a(int *stack_a, int *stack_b, int nbr, int len)
{
	while (stack_b[0] != nbr)
	{
		ft_printf("ra\n");
		ra(stack_a, len, 0);
	}
	while (find_placein_a(stack_b, nbr, len) > 0)
	{
		ft_printf("rrb\n");
		rrb(stack_b, len, 0);
	}
	pa(stack_a, stack_b, len, 0);
	ft_printf("pa\n");
	return (-1);
}
