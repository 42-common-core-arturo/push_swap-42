/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:52:31 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 04:44:22 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_byte(int *num, int *n, int *x, char *hexadecimal)
{
	*x = 8;
	if (!(*num == 0 && *n == 0))
	{
		*n = ft_putchar(hexadecimal[*num]);
		if (*n == -1)
			return (-1);
	}
	*num = 0;
	return (*n);
}

static int	ft_hex_binary(char *binary, char *hexadecimal)
{
	int	i;
	int	num;
	int	x;
	int	n;
	int	total;

	i = 0;
	num = 0;
	x = 8;
	n = 0;
	total = 0;
	while (i < 32)
	{
		num += ((binary[i++] - '0') * x);
		x /= 2;
		if (x == 0)
		{
			n = ft_print_byte(&num, &n, &x, hexadecimal);
			if (n == -1)
				return (-1);
			total += n;
		}
	}
	return (total);
}

static char	*ft_binary_buffer(int num)
{
	int		i;
	int		bits;
	char	*binary;

	i = 0;
	bits = 31;
	binary = (char *)malloc(sizeof(char) * 33);
	if (!binary)
	{
		free(binary);
		return (NULL);
	}
	while (i < 32)
	{
		binary[i++] = ((num >> bits) & 1) + '0';
		bits--;
	}
	binary[i] = '\0';
	return (binary);
}

int	ft_hex_dec(int num, char type)
{
	char	*binary;
	char	*hexadecimal;
	int		n;

	if (num == 0)
		return (ft_putchar('0'));
	binary = ft_binary_buffer(num);
	if (binary == NULL)
		return (-1);
	n = 0;
	hexadecimal = "0123456789abcdef";
	if (type == 'X')
		hexadecimal = "0123456789ABCDEF";
	n = ft_hex_binary(binary, hexadecimal);
	free(binary);
	return (n);
}
