/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:48 by msisto            #+#    #+#             */
/*   Updated: 2024/05/31 12:41:49 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	stack_dup_check(int *stack, int len)
{
	int	i;
	int	k;

	i = -1;
	while (++i < len)
	{
		k = -1;
		while (++k < len)
		{
			if (k == i)
				k++;
			if (stack[k] == stack[i])
			{
				free(stack);
				ft_custom_error(2);
			}
		}
	}
}

int	*argc_check(int argc, char **argv, int len)
{
	int		*stack_a;

	stack_a = arg_splitter(argc, argv, len);
	return (stack_a);
}
