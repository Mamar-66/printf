/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:36:18 by omfelk            #+#    #+#             */
/*   Updated: 2023/10/19 16:41:24 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *text, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, text);
	while (text[i])
	{
		ft_putchar(text[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("test");
	return (0);
}
