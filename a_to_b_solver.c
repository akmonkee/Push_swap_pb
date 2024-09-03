/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:38:56 by msisto            #+#    #+#             */
/*   Updated: 2024/06/17 11:46:17 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rr(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = find_placein_b(stack_b, nbr, len);
	if (i < index_finder(stack_a, nbr, len))
		i = index_finder(stack_a, nbr, len);
	return (i);
}

int	case_rrr(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (find_placein_b(stack_b, nbr, len))
		i = stack_size(stack_b) - find_placein_b(stack_b, nbr, len);
	if ((i < (stack_size(stack_b) - index_finder(stack_a, nbr, len))
			&& index_finder(stack_a, nbr, len)))
		i = stack_size(stack_a) - find_placein_b(stack_a, nbr, len);
	return (i);
}

int	case_rrarb(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (index_finder(stack_a, nbr, len))
		i = stack_size(stack_a) - index_finder(stack_a, nbr, len);
	i = find_placein_b(stack_b, nbr, len) + i;
	return (i);
}

int	case_rarrb(int *stack_a, int *stack_b, int nbr, int len)
{
	int	i;

	i = 0;
	if (find_placein_b(stack_b, nbr, len))
		i = stack_size(stack_b) - find_placein_b(stack_b, nbr, len);
	i = index_finder(stack_a, nbr, len);
	return (i);
}
