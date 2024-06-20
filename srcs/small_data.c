/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:19:28 by artclave          #+#    #+#             */
/*   Updated: 2024/01/05 19:16:59 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	print_list(t_list *head)
{
printf("\n");
while (head != NULL)
	{
		printf("%d\n",*(int *)head->content);
		head = head->next;
	}
	printf("\n");
}
void	shift_stack_b(t_list **head, t_list **dst)
{
	int	a0;
	int	a1;
	int	a2;
	int	b0;
	int	b1;
//	int	b2;

	a0 = *(int *)(*head)->content;
	a1 = *(int *)(*head)->next->content;
	a2 = *(int *)(*head)->next->next->content;
	b0 = *(int *)(*dst)->content;
	b1 = *(int *)(*dst)->next->content;
//	b2 = *(int *)(*dst)->next->next->content;
	if ((b0 > a0 && b0 < a1 && b1 < a2 && b1 > a1)
		|| ((b0 > a0 && b1 > a2) ))//&& !((a1 > b0 && a1 < b1))))
		return ;
	else if (b0 > a2 && b1 > a1 && b1 < a2 && ft_p(head, dst, 'a')
		&& ft_rrx(head, 'a') && ft_p(head, dst, 'a')
		&& ft_rx(head, 'a') && ft_rx(head, 'a'))
		ft_rx(head, 'a');
	else if (b0 < b1)
	{
		ft_sx(dst, 'b');
//		if (b1 > b2)
//			ft_rx(head, 'b');
	}
	if (b0 > a1 && b0 < a2 && b1 > a1 && b1 < a2 && ft_rrx(head, 'a')
		&& ft_p(head, dst, 'a') && ft_p(head, dst, 'a') && ft_rx(head, 'a')
		&& ft_rx(head, 'a'))
		ft_rx(head, 'a');
//printf("it didn't return ... \n");
}

void	rule_of_3(t_list **head)
{
	int	a0;
	int	a1;
	int	a2;

	a0 = *(int *)(*head)->content;
	a1 = *(int *)(*head)->next->content;
	a2 = *(int *)(*head)->next->next->content;
	if (a0 < a2 && a2 < a1)
	{
		ft_sx(head, 'a');
		ft_rx(head, 'a');
	}
	else if (a2 < a0 && a0 < a1)
		ft_rrx(head, 'a');
	else if (a1 < a0 && a0 < a2)
		ft_sx(head, 'a');
	else if (a1 < a2 && a2 < a0)
		ft_rx(head, 'a');
	else if (a2 < a1 && a1 < a0)
	{
		ft_sx(head, 'a');
		ft_rrx(head, 'a');
	}
}

void	refill_stack_a(t_list **head, t_list **dst)
{
	int	a0;
	int	a1;
	int	a2;
	int	b0;

	a0 = *(int *)(*head)->content;
	a1 = *(int *)(*head)->next->content;
	a2 = *(int *)(last(*head))->content;
	b0 = *(int *)(*dst)->content;
	if (b0 < a0)
		ft_p(head, dst, 'a');
	else if (b0 > a0 && b0 < a1 && ft_p(head, dst, 'a'))
		ft_sx(head, 'a');
	else if (b0 < a2 && b0 > a1 && ft_p(head, dst, 'a') && ft_rrx(head, 'a')
		&& ft_sx(head, 'a') && ft_rx(head, 'a'))
		ft_rx(head, 'a');
	else if (b0 > a2 && ft_p(head, dst, 'a'))
		ft_rx(head, 'a');
}

void	small_data_size_algorythm(t_list **head, int ac)
{
	t_list	*dst;

//	ft_printf("small data\n\n");
	dst = NULL;
	while (ac-- > 3)
		ft_p(&dst, head, 'b');
//	ft_printf("before rule2\n");
//	print_list(*head);
	rule_of_3(head);
//	ft_printf("after rule2\n");
//	print_list(*head);
//	ft_printf("b:");
//	print_list(dst);
	if (dst && dst->next)
		shift_stack_b(head, &dst);
	while (dst)
		refill_stack_a(head, &dst);
}
