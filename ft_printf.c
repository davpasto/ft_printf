/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto </var/spool/mail/davpasto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:00:54 by davpasto          #+#    #+#             */
/*   Updated: 2023/11/13 13:08:35 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
int ft_printf(const char *format, ...)
{
    va_list va;
    size_t counter;

    if (!format)
        return (0);
    counter = 0;
    va_start(va, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'c')
        {
            printf("%c", va_arg(va, int));
            counter++; // Incrementa el contador después de imprimir el carácter
            format++;
        }
        else
        {
            putchar(*format);
            counter++;
        }
        format++;
    }
    va_end(va);
    return (counter);
}

int main(void)
{
    ft_printf("%c", 'W');
    printf("\n");
    return 0;
}
