/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:56:21 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 04:49:15 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_conversion(const char *text)
{
	int	i;

	i = 0;
	if (text[i] == '%' && (text[i + 1] == 'c' || text[i + 1] == 's'
			|| text[i + 1] == 'p' || text[i + 1] == 'd' || text[i + 1] == 'i'
			|| text[i + 1] == 'u' || text[i + 1] == 'x' || text[i + 1] == 'X'))
		return (1);
	return (0);
}
