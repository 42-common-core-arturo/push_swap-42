/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:25:21 by artclave          #+#    #+#             */
/*   Updated: 2023/10/20 18:49:42 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_array_places(int **sort, int min, int j, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*sort)[i] == min && i >= j)
		{
			(*sort)[i] = (*sort)[j];
			(*sort)[j] = min;
			break ;
		}
		i++;
	}
}

int	double_nums(int *sort, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (sort[i] == sort[j])
				return (error());
			j++;
		}
		i++;
	}
	return (1);
}

int	sort_argv_ascending(int **ascending, int *sort, int ac)
{
	int	i;
	int	j;
	int	min;

	(*ascending) = (int *)malloc(sizeof(int) * (ac));
	if (!(*ascending))
		return (0);
	i = -1;
	while (++i < ac)
		(*ascending)[i] = sort[i];
	j = -1;
	while (++j < ac - 1)
	{
		i = 0;
		min = (*ascending)[j];
		while (j + i < ac)
		{
			if ((*ascending)[j + i] < min)
				min = (*ascending)[j + i];
			i++;
		}
		swap_array_places(ascending, min, j, ac);
	}
	return (1);
}

int	argv_to_stack(int ac, int *sort, t_list **head)
{
	int	i;
	int	j;
	int	content;
	int	*ascending;

	j = -1;
	if (ac == 1 || !double_nums(sort, ac) || is_array_ascending(sort, ac)
		|| !sort_argv_ascending(&ascending, sort, ac))
		return (0);
	while (++j < ac)
	{
		content = sort[j];
		i = -1;
		while (++i < ac)
		{
			if (content == ascending[i] && (!to_binary(&i)
					|| !new_node(head, i)))
			{
				free(ascending);
				return (dealloc(head));
			}
		}
	}
	free(ascending);
	return (1);
}
