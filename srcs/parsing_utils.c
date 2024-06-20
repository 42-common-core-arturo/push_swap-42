/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:18:53 by artclave          #+#    #+#             */
/*   Updated: 2023/11/15 03:42:33 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_atoi(char *str, int *i)
{
	int	negative;
	int	num;

	negative = 1;
	num = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			negative = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = (num * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (num * negative);
}

int	sign_inside_num(char *argv, int *i)
{
	while (argv[*i] != '\0')
	{
		while (argv[*i] >= '0' && argv[*i] <= '9')
			(*i)++;
		if (argv[*i] == '-' || argv[*i] == '+')
			return (1);
	}
	return (0);
}
