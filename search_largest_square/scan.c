/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:23:28 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 23:24:25 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "bsq.h"

void		scan_line(char *input)
{
	int		put_len;

	while (1)
	{
		put_len = read(0, input, 1);
		if (*input == '\n' || *input == '\0')
			break ;
		input += put_len;
	}
	*input = '\n';
}

void		map_normalize(t_map_info *map_info)
{
	int		h;
	int		w;
	char	*charset;
	char	**map;

	h = 0;
	charset = map_info->charset;
	map = map_info->map;
	while (h < map_info->h_len)
	{
		w = 0;
		while (w < map_info->w_len)
		{
			if (map[h][w] == charset[0])
				map[h][w] = '.';
			else if (map[h][w] == charset[1])
				map[h][w] = 'o';
			w++;
		}
		h++;
	}
}

t_map_info	*read_perl_output(void)
{
	char		header[300];
	char		*buf[2];
	int			h;
	t_map_info	*map_info;

	buf[0] = (char*)malloc(30000);
	buf[1] = buf[0];
	h = 0;
	scan_line(header);
	if (!check_first_col(header))
		return (NULL);
	map_info = read_header(header);
	while (h++ < map_info->h_len)
	{
		scan_line(buf[0]);
		buf[0] += ft_strlen(buf[0]) + 1;
	}
	if (buf_check(buf[1], map_info))
		return (NULL);
	map_info = buf_to_map(buf[1], map_info);
	map_info->w_len = ft_strlen(*(map_info->map));
	return (map_info);
}
