/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:57:30 by artclave          #+#    #+#             */
/*   Updated: 2023/09/12 05:42:29 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_is_conversion(const char *text);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_hex_ptr(void *num);
int	ft_digit(int num);
int	ft_unsdigit(unsigned int num);
int	ft_hex_dec(int num, char type);
int	ft_sort_conversion_type(void *variable, char id, int *i);
int	ft_printf(const char *text, ...);
#endif
