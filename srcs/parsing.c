/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:13:10 by artclave          #+#    #+#             */
/*   Updated: 2023/11/15 03:45:04 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_min_max(char *str, int neg)
{
	char	*limit;
	int		j;
	int		i;

	j = 0;
	i = 0;
	limit = "2147483648\0";
	if (neg == 0)
		limit = "2147483647\0";
	while (j < 10)
	{
		if (str[i] > limit[i])
			return (error());
		if (str[i] < limit[i])
			return (1);
		i++;
		j++;
	}
	return (1);
}

int	int_limits(int i, char *str)
{
	int	j;
	int	negative;

	negative = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i + j] >= '0' && str[i + j] <= '9')
		j++;
	if (j < 10)
		return (1);
	if (j > 10)
		return (error());
	return (int_min_max(&str[i], negative));
}

int	valid_int(int argc, char **argv, int **sort, int ac)
{
	int	i;
	int	j;
	int	x;

	*sort = (int *)malloc(sizeof(int) * ac);
	if (!(*sort))
		return (0);
	j = 0;
	x = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while (argv[j][i] == ' ')
				i++;
			if (argv[j][i] != '\0' && x < ac)
			{
				if (!int_limits(i, argv[j]))
					return (0);
				(*sort)[x++] = ft_atoi(argv[j], &i);
			}
		}
	}
	return (1);
}

int	count_data_size(int argc, char **argv, int *ac)
{
	int	i;
	int	j;

	*ac = 0;
	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while (argv[j][i] == ' ')
				i++;
			if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				i++;
				if ((argv[j][i] < '0' || argv[j][i] > '9'))
					return (error());
			}
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				(*ac)++;
			if (sign_inside_num(argv[j], &i))
				return (error());
		}
	}
	return (1);
}

int	valid_string_format(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	while (++j < argc)
	{
		flag = 0;
		i = 0;
		while (argv[j][i] == ' ' || argv[j][i] == '-' || argv[j][i] == '+'
			|| (argv[j][i] >= '0' && argv[j][i] <= '9'))
			i++;
		if (argv[j][i] != '\0')
			return (error());
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				flag = 1;
			i++;
		}
		if (flag == 0)
			return (error());
	}
	return (1);
}
