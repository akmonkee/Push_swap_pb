/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:43:34 by msisto            #+#    #+#             */
/*   Updated: 2024/09/30 13:44:11 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_custom_error(int type)
{
	if (type == 0)
	{
		write(2, "Error\n no args?\n", 16);
		exit(0);
	}
	if (type == 1)
		write(2, "Error\n ONLY NUMBERS\n", 20);
	if (type == 2)
	{
		write(2, "Error\n ONLY DIFFERENT NUMBERS\n", 30);
		exit(0);
	}
}

int	ft_atoi(char *str, int *stack)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * 10 < 0)
			return (write(2, "Error\n", 6), free(stack), exit(0), 0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((seg == -1 && num * seg > 0) || (seg == 1 && num * seg < 0))
		return (write(2, "Error\n", 6), free(stack), exit(0), 0);
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
	t_index	t_index;
	int		*stack_a;
	int		*stack_b;
	int		i;

	i = -1;
	if (argc > 1)
	{
		is_all_numbr(argc, argv);
		t_index.len = arg_mtx_len(argc, argv);
		stack_a = argc_check(argc, argv, t_index.len);
		stack_b = stack_b_gen(stack_b, t_index.len);
		sorting(stack_a, stack_b, &t_index);
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	else
		ft_custom_error(0);
}
