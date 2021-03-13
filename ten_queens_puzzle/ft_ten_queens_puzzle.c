/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:39:21 by taichika          #+#    #+#             */
/*   Updated: 2021/03/13 23:22:23 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

int		g_map[SIZE][SIZE];

int		count_line(int h, int w, int l)
{
	int i[2];

	i[1] = 0;
	i[0] = 0;
	if (l == 1)
	{
		while (i[0] < SIZE)
		{
			if (g_map[h][i[0]] == 1)
				i[1]++;
			i[0]++;
		}
	}
	else
	{
		while (i[0] < SIZE)
		{
			if (g_map[i[0]][w] == 1)
				i[1]++;
			i[0]++;
		}
	}
	if (i[1] > 1)
		return (-1);
	return (i[1]);
}

int		check_closs(int w, int h)
{
	int dif[2];
	int cnt;

	cnt = 0;
	dif[0] = -9;
	dif[1] = 9;
	while (w + dif[0] < 0 || h + dif[0] < 0)
		dif[0]++;
	while (w + dif[0] < SIZE && h + dif[0] < SIZE)
	{
		if (g_map[h + dif[0]][w + dif[0]] == 1)
			cnt++;
		dif[0]++;
	}
	while (h - dif[1] < 0 || w + dif[1] > SIZE - 1)
		dif[1]--;
	while (h - dif[1] < SIZE && w + dif[1] >= 0)
	{
		if (g_map[h - dif[1]][w + dif[1]] == 1)
			cnt++;
		dif[1]--;
	}
	if (cnt != 2)
		return (-1);
	return (0);
}

int	put_ans(int w, int h)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			if (g_map[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
				break ;
			}
			j++;
		}
		i++;
	}
	g_map[h][w] = -1;
	write(1, "\n", 1);
	return (1);
}

int		ft_rec(int h, int w, int num)
{
	int ans;

	g_map[h][w] = num;
	if (count_line(h, w, 1) == -1 || (num == 1 && check_closs(w, h) == -1))
		g_map[h][w] = -1;
	if ((w == (SIZE - 1) && (count_line(h, w, 1) != 1
		|| count_line(h, w, 0) == -1))
		|| (h == (SIZE - 1) && count_line(h, w, 0) != 1))
		g_map[h][w] = -1;
	if (g_map[h][w] != -1 && w == (SIZE - 1) && h == (SIZE - 1))
		return (put_ans(SIZE, SIZE));
	if (g_map[h][w] == -1)
		return (0);
	if (w == SIZE - 1)
	{
		ans = ft_rec(h + 1, 0, 1) + ft_rec(h + 1, 0, 0);
		g_map[h][w] = -1;
		return (ans);
	}
	else
	{
		ans = ft_rec(h, w + 1, 1) + ft_rec(h, w + 1, 0);
		g_map[h][w] = -1;
		return (ans);
	}
}

void	ft_ten_queens_puzzle(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < SIZE * SIZE)
	{
		g_map[i / SIZE][i % SIZE] = -1;
		i++;
	}
	printf("%d\n", ft_rec(0, 0, 1) + ft_rec(0, 0, 0));
	return ;
}
