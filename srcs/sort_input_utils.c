/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:03:48 by artclave          #+#    #+#             */
/*   Updated: 2023/10/20 18:49:56 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_list	*new_node(t_list **head, int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = (int *)malloc(sizeof(int));
	if (!(new->content))
		return (NULL);
	*(int *)new->content = content;
	if (*head == NULL)
		*head = new;
	else
		last(*head)->next = new;
	return (new);
}

int	dealloc(t_list **head)
{
	t_list	*temp;

	temp = NULL;
	if (*head == NULL)
		return (0);
	while (*head)
	{
		temp = (*head)->next;
		if ((*head)->content)
			free((*head)->content);
		free(*head);
		*head = temp;
	}
	return (0);
}

int	is_array_ascending(int *sort, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (sort[i] > sort[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	to_binary(int *num)
{
	int		i;
	int		bits;
	char	*binary;

	i = 0;
	bits = 32;
	binary = (char *)malloc(sizeof(char) * 33);
	if (!binary)
		return (0);
	while (i < 32 && bits--)
		binary[i++] = (((*num) >> bits) & 1) + '0';
	binary[i] = '\0';
	i = 0;
	while (binary[i] == '0')
		i++;
	*num = 0;
	while (i < 32)
		*num = ((*num) * 10) + binary[i++] - '0';
	free(binary);
	return (1);
}
