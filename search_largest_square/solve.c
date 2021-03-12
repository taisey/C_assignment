/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:42:16 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 23:16:17 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int		**make_2dintmatrix(int w_len, int h_len)
{
	int **ans;
	int h;

	h = 0;
	ans = (int **)malloc(sizeof(int *) * h_len);
	while (h < h_len)
	{
		ans[h] = (int *)malloc(sizeof(int) * w_len);
		h++;
	}
	return (ans);
}

void	determine_num(int h, int w, int **map_num)
{
	int up;
	int left;
	int upper_left;
	int ans;

	up = map_num[h - 1][w];
	left = map_num[h][w - 1];
	upper_left = map_num[h - 1][w - 1];
	if (up < left)
		ans = up;
	else
		ans = left;
	if (upper_left < ans)
		ans = upper_left;
	map_num[h][w] = ans + 1;
}

void	map_num_init(char **map, int **map_num, int w_len, int h_len)
{
	int w;
	int h;

	w = 0;
	while (w < w_len)
	{
		h = 0;
		while (h < h_len)
		{
			if (map[h][w] == '.')
				map_num[h][w] = 1;
			if (map[h][w] == 'o')
				map_num[h][w] = 0;
			h++;
		}
		w++;
	}
}

void	determine_num_all(char **map, int **map_num, int w_len, int h_len)
{
	int w;
	int h;

	w = 1;
	while (w < w_len)
	{
		h = 1;
		while (h < h_len)
		{
			if (map[h][w] != 'o')
				determine_num(h, w, map_num);
			h++;
		}
		w++;
	}
}

int		**solver(char **map, int w_len, int h_len)
{
	int	**map_num;

	map_num = make_2dintmatrix(w_len, h_len);
	map_num_init(map, map_num, w_len, h_len);
	determine_num_all(map, map_num, w_len, h_len);
	return (map_num);
}
