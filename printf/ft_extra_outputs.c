/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_outputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:17 by msisto            #+#    #+#             */
/*   Updated: 2024/02/13 11:48:33 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	char	*out;
	int		len;

	len = nlen(n);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	out[len] = '\0';
	if (n < 0)
		out[0] = '-';
	else if (n < 10 && n >= 0)
	{
		out[0] = n + 48;
		return (out);
	}
	while (len-- > 0 && n)
	{
		if (n < 0)
			out[len] = (-(n % 10)) + 48;
		else
			out[len] = (n % 10) + 48;
		n /= 10;
	}
	return (out);
}

int	ft_put_u_nbr(unsigned int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr(num);
	free(num);
	return (nlen(n));
}

int	ft_reverse_output(char *point)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (point[i])
		i++;
	while (--i > -1)
		len += ft_putchar(point[i]);
	return (len);
}

int	ft_hexvoid(void *point, int i)
{
	unsigned char	*temp;
	int				x;
	int				len;
	uintptr_t		ptr;

	len = 0;
	if (!point)
		return (ft_putchar('0'));
	ptr = (uintptr_t)point;
	x = sizeof(void *) * 2 + 1;
	temp = ft_calloc(x, sizeof(char));
	if (!temp)
		return (0);
	while (ptr)
	{
		i = ptr & 0xF;
		temp[len] = ("0123456789abcdef")[i];
		ptr >>= 4;
		len++;
	}
	temp[len] = '\0';
	len = ft_reverse_output((char *)temp);
	free(temp);
	return (len);
}
