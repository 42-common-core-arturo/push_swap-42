/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:53:50 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 01:09:20 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnum(long int num, int n)
{
	if (num < 0)
	{
		n = ft_putchar('-');
		if (n == -1)
			return (-1);
		num *= -1;
	}
	if (num > 9)
	{
		n = ft_putnum(num / 10, n);
		if (n == -1)
			return (-1);
		n = ft_putnum(num % 10, n);
	}
	if (num < 10)
		n = ft_putchar(num + '0');
	return (n);
}

int	ft_digit(int num)
{
	long int	x;
	int			digit;
	int			n;

	x = (long int)num;
	digit = 0;
	n = 0;
	if (x < 0)
	{
		x *= -1;
		digit++;
	}
	if (x == 0)
		digit++;
	while (x > 0)
	{
		x /= 10;
		digit++;
	}
	n = ft_putnum((long int)num, n);
	if (n == -1)
		return (-1);
	return (digit);
}
