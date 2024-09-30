/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_splitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:48 by msisto            #+#    #+#             */
/*   Updated: 2024/09/30 15:19:32 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mtx_free(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i] != NULL)
		free(mtx[i]);
	free(mtx);
}

int	put_split_instack(char *str, char **split, int *stack, int index)
{
	int	k;

	k = -1;
	split = ft_split(str, ' ');
	if (split == NULL || split[0] == NULL)
		return (ft_printf("Error\n"), free(stack), exit(0), 0);
	while (split[++k] != NULL)
		stack[index + k] = ft_atoi(split[k], stack);
	mtx_free(split);
	return (k);
}

int	arg_mtx_len(int argc, char **argv)
{
	int	i;
	int	k;
	int	spaces;
	int	len;

	i = 0;
	len = 0;
	while (argv[++i] != NULL && i < argc)
	{
		k = -1;
		spaces = 0;
		while (argv[i][++k] != '\0')
		{
			if (argv[i][k] == ' ')
			{
				spaces++;
			}
		}
		if (spaces != 0)
			len = len + (spaces + 1);
		else
			len++;
	}
	return (len);
}

void	stack_gen(char **argv, int *stack, int i, int index)
{
	int		k;
	int		spaces;
	char	**split;

	k = -1;
	spaces = 0;
	if (argv[i] == NULL)
		return ;
	while (argv[i][++k] != '\0')
	{
		if (argv[i][k] == ' ')
		{
			spaces++;
			k = put_split_instack(argv[i], split, stack, index);
			stack_gen(argv, stack, i + 1, index + k);
			break ;
		}
	}
	if (spaces == 0)
	{
		stack[index] = ft_atoi(argv[i], stack);
		stack_gen(argv, stack, i + 1, index + 1);
	}
}

int	*arg_splitter(int argc, char **argv, int len)
{
	int		i;
	int		*stack_a;

	i = 1;
	stack_a = malloc((len + 1) * sizeof(int));
	if (!stack_a)
		return (NULL);
	stack_gen(argv, stack_a, 1, 0);
	stack_a[len] = '\0';
	stack_dup_check(stack_a, len);
	return (stack_a);
}
