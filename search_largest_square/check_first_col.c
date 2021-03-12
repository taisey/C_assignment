/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:20:38 by yadachi           #+#    #+#             */
/*   Updated: 2021/03/10 22:07:35 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int		get_len_firstline(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}

int		check_setnbr_of_col(int i, int len, char *str)
{
	if (str[i] < '1' || '9' < str[i])
	{
		return (0);
	}
	while (i < len - 3)
	{
		if (str[i] < '0' || '9' < str[i])
		{
			return (0);
		}
		i++;
	}
	return (i);
}

int		check_first_col(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len < 4)
	{
		return (0);
	}
	i = check_setnbr_of_col(0, len, str);
	if (i == 0)
		return (0);
	if (str[i] == str[i + 1] || str[i + 1] == str[i + 2]
		|| str[i + 2] == str[i])
	{
		return (0);
	}
	return (1);
}
