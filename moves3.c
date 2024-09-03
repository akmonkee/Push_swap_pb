/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:05 by msisto            #+#    #+#             */
/*   Updated: 2024/06/05 14:11:15 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *stack_a, int *stack_b, int len, int index)
{
	rra(stack_a, len, index);
	rrb(stack_b, len, index);
}
