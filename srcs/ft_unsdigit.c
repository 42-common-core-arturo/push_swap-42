/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:53:16 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 01:13:18 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putuns(unsigned int num, int n)
{
	if (num > 9)
	{
		n = ft_putuns(num / 10, n);
		if (n == -1)
			return (-1);
		n = ft_putuns(num % 10, n);
		if (n == -1)
			return (-1);
	}
	if (num < 10)
		n = ft_putchar(num + '0');
	return (n);
}

int	ft_unsdigit(unsigned int num)
{
	unsigned int	value;
	int				digit;
	int				n;

	digit = 0;
	value = num;
	if (value == 0)
		digit++;
	while (value > 0)
	{
		value /= 10;
		digit++;
	}
	n = 0;
	n = ft_putuns(num, n);
	if (n == -1)
		return (-1);
	return (digit);
}
