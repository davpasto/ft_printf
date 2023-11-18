/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:40:34 by davpasto          #+#    #+#             */
/*   Updated: 2023/11/18 05:47:37 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define H_L_BASE "0123456789abcdef"
# define H_U_BASE "0123456789ABCDEF"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	print_char(int c);
int	print_str(char *str);
int	p_digit(long nb, int base, char *symbols);
int	print_format(char flag, va_list ap);
int	ft_printf(const char *format, ...);

#endif
