/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:36:41 by artclave          #+#    #+#             */
/*   Updated: 2024/01/06 11:51:01 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

#define VARIBALE 0
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int		min_max(char *str, int neg);
int		int_limits(int i, char *str);
int		valid_int(int argc, char **argv, int **sort, int ac);
int		count_data_size(int argc, char **argv, int *ac);
int		valid_string_format(int argc, char **argv);
int		error(void);
int		ft_atoi(char *str, int *i);
void	swap_array_places(int **sort, int min, int j, int size);
int		double_nums(int *sort, int ac);
int		sort_argv_ascending(int **ascending, int *sort, int ac);
int		argv_to_stack(int ac, int *sort, t_list **head);
t_list	*last(t_list *head);
t_list	*new_node(t_list **head, int content);
int		dealloc(t_list **head);
int		is_array_ascending(int *sort, int len);
int		to_binary(int *num);
void	large_data_size_algorythm(t_list **head, int num, int data_size);
int		stack_is_sorted(t_list *a, t_list *b);
int		radix_digit(int num, int max);
int		find_max_digits(int max);
void	shift_stack_b(t_list **head, t_list **dst);
void	refill_stack_a(t_list **head, t_list **dst);
void	rule_of_3(t_list **head);
void	small_data_size_algorythm(t_list **head, int ac);
int		ft_rrx(t_list **head, char print);
int		ft_rx(t_list **head, char print);
int		ft_sx(t_list **head, char print);
int		ft_p(t_list **dst, t_list **src, char print);
int		sign_inside_num(char *argv, int *i);
#endif
