/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:48:46 by tyoshida          #+#    #+#             */
/*   Updated: 2021/03/07 22:30:02 by tyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		strcmp_partly(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0')
	{
		while (*s2 == ' ')
			s2++;
		if (*s2 == ':')
			return (0);
		else
			return (-1);
	}
	return ((int)*s1 - (int)*s2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnumber(unsigned int num)
{
	if (num < 0)
	{
		num = num * -1;
		ft_putchar('-');
	}
	if (num <= 9)
		ft_putchar(num);
	else
	{
		ft_putnumber(num / 10);
		ft_putnumber(num % 10);
	}
}

void	ft_putstring(char *c)
{
	int i;

	i = -1;
	while (c[++i])
		ft_putchar(c[i]);
}

void	ft_puterr(int i)
{
	if (i == 1)
		write(1, "Error\n", 6);
	else
		write(1, "Dict Error\n", 11);
}
