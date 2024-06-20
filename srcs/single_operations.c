/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:27:46 by artclave          #+#    #+#             */
/*   Updated: 2024/01/05 18:24:41 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_p(t_list **dst, t_list **src, char print)
{
	t_list	*copy_src;
	t_list	*copy_dst;

	if (*src == NULL)
		return (0);
	copy_src = *src;
	*src = (*src)->next;
	copy_dst = *dst;
	*dst = copy_src;
	(*dst)->next = copy_dst;
	ft_printf("p%c\n", print);
	return (1);
}

int	ft_sx(t_list **head, char print)
{
	t_list	*copy_node0;
	t_list	*copy_node2;
	t_list	*curr;

	if (*head == NULL || (*head)->next == NULL)
		return (0);
	curr = *head;
	copy_node0 = curr;
	copy_node2 = curr->next->next;
	*head = curr->next;
	curr = *head;
	curr->next = copy_node0;
	curr->next->next = copy_node2;
	if (print != '\0')
		ft_printf("s%c\n", print);
	return (1);
}

int	ft_rx(t_list **head, char print)
{
	t_list	*copy_node0;
	t_list	*curr;

	curr = *head;
	copy_node0 = *head;
	*head = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = copy_node0;
	curr->next->next = NULL;
	if (print != '\0')
		ft_printf("r%c\n", print);
	return (1);
}

int	ft_rrx(t_list **head, char print)
{
	t_list	*copy_last;
	t_list	*copy_node0;
	t_list	*curr;

	curr = *head;
	copy_node0 = *head;
	while (curr->next->next != NULL)
		curr = curr->next;
	copy_last = curr->next;
	curr->next = NULL;
	copy_node0 = *head;
	*head = copy_last;
	(*head)->next = copy_node0;
	if (print != '\0')
		ft_printf("rr%c\n", print);
	return (1);
}
