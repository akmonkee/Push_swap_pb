/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:12:11 by msisto            #+#    #+#             */
/*   Updated: 2024/02/14 12:06:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		i;
	char	*n;

	n = "(null)";
	i = -1;
	if (!s)
	{
		while (n[++i])
			write(1, &n[i], 1);
		return (i);
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr(num);
	free(num);
	return (nlen(n));
}

static int	ft_hex_put(long n, int i, char *base)
{
	unsigned int	x;

	x = (unsigned int)n;
	if (x >= 16)
	{
		i = ft_hex_put(x / 16, i, base);
		i = ft_hex_put(x % 16, i, base);
	}
	else
		i += ft_putchar(base[x]);
	return (i);
}

int	ft_putnbr_base(long n, int type)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (!n)
		return (ft_putchar('0'));
	if (type == 2)
		base = "0123456789ABCDEF";
	i = ft_hex_put(n, i, base);
	return (i);
}
