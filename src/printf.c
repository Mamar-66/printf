/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:36:18 by omfelk            #+#    #+#             */
/*   Updated: 2023/10/20 18:34:56 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <limits.h>

int	type_format(va_list args, const char format)
{
	int		size;

	size = 0;
	if (format == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (format == 'p')
	{
		size = ft_putstr("0x");
		size += ft_putnbr_base(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	else if (format == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (format == 'x')
		size += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		size += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (format == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	int			i;
	int			total_size;

	i = 0;
	total_size = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
			total_size += type_format(args, text[i++ + 1]);
		else
			total_size += ft_putchar(text[i]);
		i++;
	}
	va_end(args);
	return (total_size);
}
/*
int	main(void)
{
	int		v;
	int		f;
	char	*c = " | dans le ptr | ";

	f = ft_printf("caract = %c string =  %s d = %d i = %i hexa %x HEXA %X le %% le p = %p\n", 'c', "| le s |", INT_MAX, INT_MIN, 22255, -200, c);
	v = printf("caract = %c string =  %s d = %d i = %i hexa %x HEXA %X le %% le p = %p\n", 'c', "| le s |", INT_MAX, INT_MIN, 22255, -200, c);
	printf("f = %d\n", f);
	printf("v = %d\n", v);
	return (0);
}*/
