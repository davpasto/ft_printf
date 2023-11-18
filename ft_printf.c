/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto </var/spool/mail/davpasto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:00:54 by davpasto          #+#    #+#             */
/*   Updated: 2023/11/18 06:34:40 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define H_L_BASE "0123456789abcdef"
#define H_U_BASE "0123456789ABCDEF"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	char	*ptr = NULL;

	ptr = str;
	if (!str)
		return (write(1, "(null)", 6));
	while (*ptr)
	{
		if (write(1, ptr, 1) == -1)
			return (-1);
		++ptr;
	}
	return (ptr - str);
}

int	p_digit(long nb, int base, char *symbols)
{
	int		count;

	if (nb < 0)
	{
		write(1, "-", 1);
		return (p_digit(-nb, base, symbols) + 1);
	}
	else if (nb < base)
		return (print_char(symbols[nb]));
	else
	{
		count = p_digit(nb / base, base, symbols);
		return (count + p_digit(nb % base, base, symbols));
	}
}

int	print_format(char flag, va_list ap)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count += print_char(va_arg(ap, int));
	else if (flag == 's')
		count += print_str(va_arg(ap, char *));
	else if (flag == 'd' || flag == 'i')
		count += p_digit((long)va_arg(ap, int), 10, H_L_BASE);
	else if (flag == 'x')
		count += p_digit((long)va_arg(ap, unsigned int), 16, H_L_BASE);
	else if (flag == 'X')
		count += p_digit((long)va_arg(ap, unsigned int), 16, H_U_BASE);
	else if (flag == 'u')
		count += p_digit((unsigned int)va_arg(ap, unsigned int), 10, H_L_BASE);
	else if (flag == '%')
		return (print_char('%'));
	else if (flag == 'p')
	{
		count += write(1, "0x", 2);
		count += p_digit((unsigned long long)va_arg(ap, void *), 16, H_L_BASE);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		counter;

	if (!format)
		return (-1);
	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			counter += print_format(*(++format), ap);
		else
			counter += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (counter);
}

int	main()
{
	char *ptr = "Hola";
	//ft_printf("%p\n", ptr);
	//printf("%p\n", ptr);
	//printf("%d\n", printf("%p\n", ptr));
	printf("%d\n", ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX));
	printf("%d\n", printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX));
}
