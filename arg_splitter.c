/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_splitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:48 by msisto            #+#    #+#             */
/*   Updated: 2024/10/04 15:40:18 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mtx_free(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i] != NULL)
		free(mtx[i]);
	free(mtx);
}

int	put_split_instack(char *str, char **split, int *stack, int index)
{
	int	k;

	k = 0;
	split = ft_split(str, ' ');
	if (split == NULL || split[0] == NULL)
		return (ft_printf("Error\n"), free(stack), mtx_free(split), exit(0), 0);
	while (split[k] != NULL)
	{
		stack[index + k] = ft_atoi(split[k], stack);
		k++;
	}
	mtx_free(split);
	return (k);
}

int	arg_mtx_len(int argc, char **argv)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	len = 0;
	while (argv[++i] != NULL && i < argc)
	{
		k = -1;
		if (ft_strlen(argv[i]) > 2)
			while (argv[i][++k] != '\0')
			{
				if (argv[i][k] >= '0' && argv[i][k] <= '9')
				{
					while ((argv[i][k] >= '0' && argv[i][k] <= '9')
						&& k < ft_strlen(argv[i]) - 1)
						k++;
					len++;
				}
			}
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
	int		*stack_a;

	stack_a = malloc((len + 1) * sizeof(int));
	if (!stack_a)
		return (NULL);
	stack_gen(argv, stack_a, 1, 0);
	stack_a[len] = '\0';
	stack_dup_check(stack_a, len);
	return (stack_a);
}
