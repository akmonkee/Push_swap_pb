/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:22:02 by msisto            #+#    #+#             */
/*   Updated: 2024/02/14 12:03:19 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_which_fun(va_list *ap, const char l)
{
	int	i;

	i = 0;
	if (l == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (l == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (l == 'p')
		return (ft_putstr("0x") + ft_hexvoid(va_arg(*ap, void *), i));
	else if (l == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (l == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (l == 'u')
		return (ft_put_u_nbr(va_arg(*ap, int)));
	else if (l == 'x')
		return (ft_putnbr_base(va_arg(*ap, int), 1));
	else if (l == 'X')
		return (ft_putnbr_base(va_arg(*ap, int), 2));
	else
		return (ft_putchar(l));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;

	i = -1;
	num = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			num += ft_which_fun(&ap, str[i]);
		}
		else
			num += ft_putchar(str[i]);
	}
	va_end(ap);
	return (num);
}
/*
#include <stdio.h>
int main()
{
	printf("NULL %s NULL", NULL);
	printf("%c", '\n');
	ft_printf("NULL %s NULL", NULL);
}
*/
