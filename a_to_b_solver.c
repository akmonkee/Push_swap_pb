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

int	case_rr(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = find_placein_b(stack_b, nbr, t_index->index_b);
	if (i < index_finder(stack_a, nbr, t_index->index_a))
		i = index_finder(stack_a, nbr, t_index->index_a);
	return (i);
}

int	case_rrr(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (find_placein_b(stack_b, nbr, t_index->index_b))
		i = t_index->index_b + find_placein_b(stack_b, nbr, t_index->index_b);
	if ((i < (t_index->index_a + index_finder(stack_a, nbr, t_index->index_a))
			&& index_finder(stack_a, nbr, t_index->index_a)))
		i = t_index->index_a + index_finder(stack_a, nbr, t_index->index_a);
	return (i);
}

int	case_rrarb(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (index_finder(stack_a, nbr, t_index->index_a))
		i = t_index->index_a + index_finder(stack_a, nbr, t_index->index_a);
	i = find_placein_b(stack_b, nbr, t_index->index_b) + i;
	return (i);
}

int	case_rarrb(int *stack_a, int *stack_b, int nbr, t_index *t_index)
{
	int	i;

	i = 0;
	if (find_placein_b(stack_b, nbr, t_index->index_b))
		i = t_index->index_b + find_placein_b(stack_b, nbr, t_index->index_b);
	i = index_finder(stack_a, nbr, t_index->index_a) + i;
	return (i);
}
