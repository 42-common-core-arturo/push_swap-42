/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:55:28 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 04:50:45 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	n;
	int	total;

	n = 0;
	total = 0;
	if (str == NULL)
	{
		n = ft_putstr("(null)");
		return (n);
	}
	i = 0;
	while (str[i])
	{
		n = ft_putchar(str[i]);
		if (n == -1)
			return (-1);
		total += n;
		i++;
	}
	return (total);
}
