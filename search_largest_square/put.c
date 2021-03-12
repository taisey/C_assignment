/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:23:34 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 22:45:51 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include <fcntl.h>

void	put_map_error(void)
{
	write(2, "map error\n", 10);
}

void	put_nbr_rec(int nbr)
{
	int		div;
	int		mod;
	char	c;

	if (nbr == 0)
		return ;
	div = nbr / 10;
	mod = nbr % 10;
	put_nbr_rec(div);
	c = '0' + mod;
	write(1, &c, 1);
}

void	put_nbr(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	put_nbr_rec(nbr);
}

void	put_2dintmatrix(int **matrix, int w_len, int h_len)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (h < h_len)
	{
		w = 0;
		while (w < w_len)
		{
			put_nbr(matrix[h][w]);
			write(1, " ", 1);
			w++;
		}
		write(1, "\n", 1);
		h++;
	}
}

void	put_2dcharmatrix(char **matrix, int w_len, int h_len)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (h < h_len)
	{
		w = 0;
		while (w < w_len)
		{
			write(1, &matrix[h][w], 1);
			w++;
		}
		write(1, "\n", 1);
		h++;
	}
}
