/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 00:02:36 by rsudo             #+#    #+#             */
/*   Updated: 2021/03/13 01:17:21 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	return_num;

	i = 0;
	return_num = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		return_num *= 10;
		return_num += str[i] - '0';
		i++;
	}
	return (return_num);
}

int				argument_is_valid(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '+'))
		{
			if (!(argv[i] == ' ' || argv[i] == '\f' || argv[i] == '\n' ||
			argv[i] == '\r' || argv[i] == '\t' || argv[i] == '\v'))
				return (0);
		}
		i++;
	}
	if (i > 10)
		return (0);
	return (1);
}
