/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:25:43 by yadachi           #+#    #+#             */
/*   Updated: 2021/03/10 23:18:59 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "bsq.h"

void	solve_and_put(t_map_info *map_info)
{
	char	**map;
	int		**map_num;
	int		h_len;
	int		w_len;
	int		*max_h_w;

	map = map_info->map;
	h_len = map_info->h_len;
	w_len = map_info->w_len;
	map_num = solver(map, w_len, h_len);
	max_h_w = find_maxcoor(map_num, w_len, h_len);
	fill_full(map, max_h_w);
	map_decode(map_info);
	put_2dcharmatrix(map, w_len, h_len);
}

void	start_search_in_main(t_map_info *map_info)
{
	if (map_info == NULL)
		write(1, "map error\n", 11);
	else
	{
		map_normalize(map_info);
		solve_and_put(map_info);
	}
}

int		main(int argc, char **argv)
{
	t_map_info	*map_info;
	int			i;

	i = 1;
	if (argc == 1)
	{
		map_info = read_perl_output();
		start_search_in_main(map_info);
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			map_info = file_to_map(argv[i]);
			i++;
			start_search_in_main(map_info);
			if (i < argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}
