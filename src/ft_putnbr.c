/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:09:46 by omfelk            #+#    #+#             */
/*   Updated: 2023/10/20 11:45:23 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_write(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_write((n / 10));
		ft_write((n % 10));
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n >= -2147483647 && n <= 2147483647)
	{
		ft_write(n);
		while (n > 0)
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}
/*
int	main()
{
	printf ("n = %d\n", ft_putnbr(1));
	return (0);
}*/