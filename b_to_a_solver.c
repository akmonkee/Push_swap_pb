/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:23:12 by msisto            #+#    #+#             */
/*   Updated: 2024/06/18 12:29:29 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rr_a(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = find_placein_a(stack_b, nbr, len);
	if (i < index_finder(stack_b, nbr, len))
		i = index_finder(stack_b, nbr, len);
	return (i);
}

int	case_rrr_a(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (find_placein_a(stack_b, nbr, len))
		i = stack_size(stack_a) - find_placein_a(stack_a, nbr, len);
	if ((i < (stack_size(stack_a) - index_finder(stack_b, nbr, len))
			&& index_finder(stack_b, nbr, len)))
		i = stack_size(stack_b) - find_placein_b(stack_b, nbr, len);
	return (i);
}

int	case_rrarb_a(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (find_placein_a(stack_b, nbr, len))
		i = stack_size(stack_a) - find_placein_a(stack_a, nbr, len);
	i = index_finder(stack_b, nbr, len);
	return (i);
}

int	case_rarrb_a(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (index_finder(stack_b, nbr, len))
		i = stack_size(stack_b) - index_finder(stack_b, nbr, len);
	i = find_placein_a(stack_b, nbr, len) + i;
	return (i);
}
