/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:12:37 by msisto            #+#    #+#             */
/*   Updated: 2024/06/18 11:54:26 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_checker(int *stack, int len, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		while (i < len)
		{
			if (stack[i + 1] != '\0' && stack[i] < stack[i + 1])
				return (0);
			i++;
		}
	}
	if (type == 1)
	{
		while (i < len)
		{
			if (stack[i + 1] != '\0' && stack[i] > stack[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

void	print_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	ft_printf("--------------------------------\n");
}
