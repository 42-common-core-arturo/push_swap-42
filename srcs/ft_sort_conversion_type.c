/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_conversion_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:51:26 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 16:44:23 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort_conversion_type(void *variable, char id, int *i)
{
	int	n;

	n = 0;
	if (id == 'c')
		n = ft_putchar((char)variable);
	else if (id == 's')
		n = ft_putstr((char *)variable);
	else if (id == 'p')
		n = ft_hex_ptr(variable);
	else if (id == 'd' || id == 'i')
		n = ft_digit((int)variable);
	else if (id == 'u')
		n = ft_unsdigit((unsigned int)variable);
	else if (id == 'x' || id == 'X')
		n = ft_hex_dec((int)variable, id);
	*i = *i + 2;
	return (n);
}
