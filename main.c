/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:43:34 by msisto            #+#    #+#             */
/*   Updated: 2024/06/06 11:10:27 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_custom_error(int type)
{
	if (type == 0)
		write(2, "Error\n no args?", 16);
	if (type == 1)
		write(2, "Error\n ONLY NUMBERS", 20);
	if (type == 2)
		write(2, "Error\n ONLY DIFFERENT NUMBERS", 30);
	exit(0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	seg;
	int	i;

	num = 0;
	seg = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			seg = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (ft_custom_error(1), exit(0), 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * 10 < 0)
			return (write(2, "Pesce", 5), exit(-1), 0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((seg == -1 && num * seg > 0) || (seg == 1 && num * seg < 0))
		return (write(2, "Pesce", 5), exit(-1), 0);
	return (num * seg);
}

int	*stack_b_gen(int *stack_b, int len)
{
	int	i;

	i = 0;
	stack_b = malloc((len + 1) * sizeof(int));
	if (!stack_b)
		return (0);
	while (i < len)
	{
		stack_b[i] = 0;
		i++;
	}
	stack_b[len] = '\0';
	return (stack_b);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	len;
	int	i;

	i = -1;
	if (argc > 2)
	{
		len = arg_mtx_len(argc, argv);
		stack_a = argc_check(argc, argv, len);
		stack_b = stack_b_gen(stack_b, len);
		sorting(stack_a, stack_b, len);
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	if (argc == 2)
		write(2, "Error\n", 6);
	else
		ft_custom_error(0);
}
