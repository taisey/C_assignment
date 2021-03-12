/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invaild_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:09:50 by yadachi           #+#    #+#             */
/*   Updated: 2021/03/10 17:09:46 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int		count_col(t_map_info *map_info, char **lines)
{
	if (map_info->h_len != ft_strlen(*lines))
	{
		put_map_error();
		return (0);
	}
	return (1);
}

int		check_col_len(int len, char *cols)
{
	if (ft_strlen(cols) != len)
		return (0);
	return (1);
}

int		check_col_char(char *cols, char *charset)
{
	int	i;

	i = 0;
	while (cols[i] != '\0')
	{
		if (cols[i] < 32 || 126 < cols[i])
			return (0);
		if (cols[i] != charset[0] && cols[i] != charset[1])
			return (0);
		i++;
	}
	return (1);
}

int		check_invaild_map(char *cols, t_map_info *t_map)
{
	if (t_map->w_len == 0)
		t_map->w_len = ft_strlen(cols);
	if (!check_col_len(t_map->w_len, cols) ||
		!check_col_char(cols, t_map->charset))
	{
		put_map_error();
		return (0);
	}
	return (1);
}

char	*oneline_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = get_len_firstline(src);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
