/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:14:24 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 23:22:12 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int		*find_maxcoor(int **map_num, int w_len, int h_len)
{
	int	w;
	int	h;
	int	*max_h_w;

	max_h_w = (int *)malloc(3);
	w = 0;
	max_h_w[0] = 0;
	max_h_w[1] = 0;
	max_h_w[2] = 0;
	while (w < w_len)
	{
		h = 0;
		while (h < h_len)
		{
			if (map_num[h][w] > max_h_w[0])
			{
				max_h_w[0] = map_num[h][w];
				max_h_w[1] = h;
				max_h_w[2] = w;
			}
			h++;
		}
		w++;
	}
	return (max_h_w);
}

void	fill_full(char **map, int *max_h_w)
{
	int	max;
	int	h;
	int	w;

	max = max_h_w[0];
	h = max_h_w[1];
	w = max_h_w[2];
	while (h > max_h_w[1] - max)
	{
		w = max_h_w[2];
		while (w > max_h_w[2] - max)
		{
			map[h][w] = 'x';
			w--;
		}
		h--;
	}
}

void	map_decode(t_map_info *map_info)
{
	char	*charset;
	int		h;
	int		w;
	char	c;
	char	**map;

	map = map_info->map;
	charset = map_info->charset;
	h = 0;
	while (h < map_info->h_len)
	{
		w = 0;
		while (w < map_info->w_len)
		{
			c = map[h][w];
			if (c == '.')
				map[h][w] = charset[0];
			else if (c == 'o')
				map[h][w] = charset[1];
			else if (c == 'x')
				map[h][w] = charset[2];
			w++;
		}
		h++;
	}
}
