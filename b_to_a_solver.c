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

int	case_rr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = find_placein_a(stack_a, nbr, t_index->index_a);
	if (i < index_finder(stack_b, nbr, t_index->index_b))
		i = index_finder(stack_b, nbr, t_index->index_b);
	return (i);
}

int	case_rrr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (find_placein_a(stack_a, nbr, t_index->index_a))
		i = t_index->index_a + find_placein_a(stack_a, nbr, t_index->index_a);
	if ((i < (t_index->index_b + index_finder(stack_b, nbr, t_index->index_b))
			&& index_finder(stack_b, nbr, t_index->index_b)))
		i = t_index->index_b + index_finder(stack_b, nbr, t_index->index_b);
	return (i);
}

int	case_rrarb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (find_placein_a(stack_a, nbr, t_index->index_a))
		i = t_index->index_a + find_placein_a(stack_a, nbr, t_index->index_a);
	i = index_finder(stack_b, nbr, t_index->index_b) + i;
	return (i);
}

int	case_rarrb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (index_finder(stack_b, nbr, t_index->index_b))
		i = t_index->index_b + index_finder(stack_b, nbr, t_index->index_b);
	i = find_placein_a(stack_a, nbr, t_index->index_a) + i;
	return (i);
}
