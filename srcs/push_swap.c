/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:38:16 by artclave          #+#    #+#             */
/*   Updated: 2024/01/05 19:15:35 by artclave         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	t_list	*head;
	int		*sort;
	int		ac;

	head = NULL;
	sort = NULL;
	if (!valid_string_format(argc, argv) || !count_data_size(argc, argv, &ac)
		|| !valid_int(argc, argv, &sort, ac) || !argv_to_stack(ac, sort, &head))
	{
		if (sort)
			free(sort);
		return (0);
	}
	if (ac >= 6)
		large_data_size_algorythm(&head, ac - 1, ac);
//	print_list(head);
	if (ac == 2)
		ft_sx(&head, 'a');
	else
		small_data_size_algorythm(&head, ac);
//	print_list(head);
	free(sort);
	dealloc(&head);
	return (1);
}
