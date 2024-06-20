/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:48:41 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 05:44:05 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_no_conversion(const char *text, int i, int *n)
{
	if (text[i] == '%' && text[i + 1] == '%')
	{
		*n = ft_putchar('%');
		i += 2;
	}
	else
		*n = ft_putchar(text[i++]);
	return (i);
}

int	ft_printf(const char *text, ...)
{
	va_list	array;
	int		i;
	int		n;
	int		total;

	va_start(array, text);
	n = 0;
	i = 0;
	total = 0;
	if (!text[i])
		return (0);
	while (text[i])
	{
		if (ft_is_conversion(&text[i]))
			n = ft_sort_conversion_type(va_arg(array, void *), text[i + 1], &i);
		else
			i = ft_no_conversion(text, i, &n);
		if (n == -1)
			return (-1);
		total += n;
		va_end(array);
	}
	return (total);
}
