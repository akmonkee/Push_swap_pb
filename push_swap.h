/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:43 by msisto            #+#    #+#             */
/*   Updated: 2024/10/07 11:30:31 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "printf/ft_printf.h"

typedef struct t_index
{
	int	index_a;
	int	index_b;
	int	len;
}	t_index;

void	is_all_numbr(int argc, char**argv);
int		order_checker(int *stack, int len, int type);
void	print_stack(int *stack_a, int *stack_b, t_index *t_index);
/*split and friends*/
char	**ft_split(const char *str, char c);
void	aux(char **arr, const char *str, char c);
void	new_string(const char *str, int start, int end, char *dest);
int		count_words(const char *str, char c);
/*stack generator and arg check*/
int		ft_atoi(char *str, int *stack);
void	ft_custom_error(int type);
int		*argc_check(int argc, char **argv, int len);
void	stack_dup_check(int *stack, int len);
int		*arg_splitter(int argc, char **argv, int len);
int		ft_strlen(const char *str);
int		arg_mtx_len(int argc, char **argv);
void	stack_gen(char **argv, int *stack, int i, int index);
void	mtx_free(char **mtx);
void	inv_arg_check(char **argv);
int		put_split_instack(char *str, char **split, int *stack, int index);
int		*stack_b_gen(int *stack_b, int len);
/*if len is 3*/
void	sort_three_util(int	*stack, t_index *t_index);
void	sort_three(int	*stack, t_index *t_index);
/*moves*/
void	sa(int *stack_a, int index);
void	sb(int *stack_b, int index);
void	ss(int *stack_a, int *stack_b, int index);
void	pa(int *stack_a, int *stack_b, t_index *t_index, int index);
void	pb(int *stack_a, int *stack_b, t_index *t_index, int index);
void	ra(int *stack_a, t_index *t_index, int index);
void	rb(int *stack_b, t_index *t_index, int index);
void	rr(int *stack_a, int *stack_b, t_index *t_index, int index);
void	rra(int *stack_a, t_index *t_index, int index);
void	rrb(int *stack_b, t_index *t_index, int index);
void	rrr(int *stack_a, int *stack_b, t_index *t_index, int index);
/*utils*/
int		max_of_stack(int *stack, int len);
int		min_of_stack(int *stack, int len);
int		stack_size(int *stack);
int		last_finder(int *stack, int len);
int		index_finder(int *stack, int nbr, int len);
int		find_placein_a(int *stack, int nbr, int len);
int		find_placein_b(int *stack, int nbr, int len);
/*a to b solver*/
int		case_rr(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rrr(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rrarb(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rarrb(int *stack_a, int *stack_b, int nbr, t_index *t_index);
/*b to a solver*/
int		case_rr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rrr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rrarb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		case_rarrb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
/*rotate type*/
int		rotate_type_ab(int	*stack_a, int *stack_b, t_index *t_index);
int		rotate_type_ba(int	*stack_a, int *stack_b, t_index *t_index);
/*apply_moves*/
int		ft_apply_rr_b(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		ft_apply_rrarrb_b(int *stack_a, int *stack_b,
			int nbr, t_index *t_index);
int		ft_apply_rrarb_b(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		ft_apply_rarrb_b(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		ft_apply_rr_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		ft_apply_rrarrb_a(int *stack_a, int *stack_b,
			int nbr, t_index *t_index);
int		ft_apply_rrarb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
int		ft_apply_rarrb_a(int *stack_a, int *stack_b, int nbr, t_index *t_index);
/*is sorted*/
int		is_sorted(int *stack, t_index *t_index, char type);
/*sorter*/
void	sort_a(int *stack_a, int *stack_b, t_index *t_index);
void	sort(int *stack_a, int *stack_b, t_index *t_index);
void	sort_to_b_3(int *stack_a, int *stack_b, t_index *t_index);
void	sorting(int *stack_a, int *stack_b, t_index *t_index);
void	min_nbr_top(int *stack_a, t_index *t_index);

#endif
