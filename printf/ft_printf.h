/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:10:28 by msisto            #+#    #+#             */
/*   Updated: 2024/05/28 11:04:35 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		nlen(long n);
int		ft_putnbr(int n);
int		ft_put_u_nbr(unsigned int n);
int		ft_putstr(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(long n);
int		ft_putnbr_base(long n, int type);
int		ft_reverse_output(char *point);
int		ft_hexvoid(void *point, int i);

#endif
