/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:52:31 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 04:46:03 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_binary(char *binary, char *hexadecimal, int i, int num)
{
	int		x;
	int		n;
	int		total;

	x = 8;
	n = 0;
	total = 0;
	while (i < 64)
	{
		num += ((binary[i++] - '0') * x);
		x /= 2;
		if (x == 0)
		{
			x = 8;
			if (!(num == 0 && n == 0))
			{
				n = ft_putchar(hexadecimal[num]);
				if (n == -1)
					return (-1);
				total += n;
			}
			num = 0;
		}
	}
	return (total);
}

static int	ft_binary_buffer(long long value)
{
	char	*binary;
	int		bits;
	int		i;

	binary = (char *)malloc(sizeof(char) * 65);
	if (!binary)
	{
		free(binary);
		return (-1);
	}
	bits = 63;
	i = 0;
	while (i < 64)
	{
		binary[i++] = ((value >> bits) & 1) + '0';
		bits--;
	}
	binary[i] = '\0';
	i = ft_hex_binary(binary, "0123456789abcdef", 0, 0);
	free (binary);
	return (i);
}

int	ft_hex_ptr(void *num)
{
	long long	value;
	int			n;
	int			total;

	value = (long long)num;
	n = 0;
	total = 0;
	if (value == 0)
	{
		n = ft_putstr("0x0");
		return (n);
	}
	n = ft_putstr("0x");
	if (n == -1)
		return (-1);
	total += n;
	n = ft_binary_buffer(value);
	if (n == -1)
		return (-1);
	total += n;
	return (total);
}
