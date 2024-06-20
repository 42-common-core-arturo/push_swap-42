/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_data_size_algorythm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:33:20 by artclave          #+#    #+#             */
/*   Updated: 2024/01/05 19:15:56 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_digits(int max)
{
	int	digits;

	digits = 0;
	to_binary(&max);
	while (max != 0)
	{
		max /= 10;
		digits++;
	}
	return (digits);
}

int	radix_digit(int num, int max)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < max)
	{
		result = num % 10;
		num /= 10;
		i++;
	}
	return (result);
}

int	stack_is_sorted(t_list *a, t_list *b)
{
	if (b || !a)
		return (0);
	while (a && a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	large_data_size_algorythm(t_list **head, int num, int data_size)
{
	int		i;
	int		j;
	int		len;
	t_list	*dst;

//	ft_printf("large_data\n\n");
	to_binary(&num);
	len = 0;
	while (num != 0 && len++ >= 0)
		num /= 10;
	dst = NULL;
	i = -1;
	while (++i < len && !stack_is_sorted(*head, dst))
	{
		j = -1;
		while (++j < data_size)
		{
			if (radix_digit(*(int *)(*head)->content, i + 1) == 0)
				ft_p(&dst, head, 'b');
			else
				ft_rx(head, 'a');
		}
		while (dst)
			ft_p(head, &dst, 'a');
	}
}
