/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:43 by msisto            #+#    #+#             */
/*   Updated: 2024/06/20 12:14:07 by msisto           ###   ########.fr       */
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

void	sorting(int *stack_a, int *stack_b, int len);
int		order_checker(int *stack, int len, int type);
void	print_stack(int *stack, int len);
/*split and friends*/
char	**ft_split(const char *str, char c);
void	aux(char **arr, const char *str, char c);
void	new_string(const char *str, int start, int end, char *dest);
int		count_words(const char *str, char c);
/*stack generator and arg check*/
int		ft_atoi(char *str);
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
void	sort_three(int	*stack, int len);
/*moves*/
void	sa(int *stack_a, int len, int index);
void	sb(int *stack_b, int len, int index);
void	ss(int *stack_a, int *stack_b, int len, int index);
void	pa(int *stack_a, int *stack_b, int len, int index);
void	pb(int *stack_a, int *stack_b, int len, int index);
void	ra(int *stack_a, int len, int index);
void	rb(int *stack_b, int len, int index);
void	rr(int *stack_a, int *stack_b, int len, int index);
void	rra(int *stack_a, int len, int index);
void	rrb(int *stack_b, int len, int index);
void	rrr(int *stack_a, int *stack_b, int len, int index);
/*utils*/
int		max_of_stack(int *stack, int len);
int		min_of_stack(int *stack, int len);
int		stack_size(int *stack);
int		last_finder(int *stack, int len);
int		index_finder(int *stack, int max_nbr, int len);
int		find_placein_a(int *stack, int nbr, int len);
int		find_placein_b(int *stack, int nbr, int len);
/*a to b solver*/
int		case_rr(int *stack_a, int *stack_b, int nbr, int len);
int		case_rrr(int *stack_a, int *stack_b, int nbr, int len);
int		case_rrarb(int *stack_a, int *stack_b, int nbr, int len);
int		case_rarrb(int *stack_a, int *stack_b, int nbr, int len);
/*b to a solver*/
int		case_rr_a(int *stack_a, int *stack_b, int nbr, int len);
int		case_rrr_a(int *stack_a, int *stack_b, int nbr, int len);
int		case_rrarb_a(int *stack_a, int *stack_b, int nbr, int len);
int		case_rarrb_a(int *stack_a, int *stack_b, int nbr, int len);
/*rotate type*/
int		rotate_type_ab(int	*stack_a, int *stack_b, int len);
int		rotate_type_ba(int	*stack_a, int *stack_b, int len);
/*apply_moves*/
int		ft_apply_rr_b(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rrarrb_b(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rrarb_b(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rarrb_b(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rr_a(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rrarrb_a(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rrarb_a(int *stack_a, int *stack_b, int nbr, int len);
int		ft_apply_rarrb_a(int *stack_a, int *stack_b, int nbr, int len);
/*is sorted*/
int		is_sorted(int *stack, int len, char type);
/*sorter*/
void	sort_a(int *stack_a, int *stack_b, int len);
void	sort_b(int *stack_a, int *stack_b, int len);
void	sort_to_b_3(int *stack_a, int *stack_b, int len);

#endif
