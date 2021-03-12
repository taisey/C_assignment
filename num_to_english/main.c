/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:32:54 by tyoshida          #+#    #+#             */
/*   Updated: 2021/03/13 02:47:53 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	main_body(char *dict_name, char *arg)
{
	int f;

	if ((argument_is_valid(arg)))
	{
		f = open(dict_name, O_RDONLY);
		if (f == -1)
		{
			ft_puterr(0);
			return ;
		}
		close(f);
		ptr_all_digit(ft_atoi(arg), 0, dict_name);
	}
	else
		ft_puterr(0);
}

int		main(int arg, char **argv)
{
	char *default_name;

	default_name = "numbers.dict";
	if (arg == 2)
		main_body(default_name, argv[1]);
	else if (arg == 3)
		main_body(argv[1], argv[2]);
	else
	{
		ft_puterr(0);
		return (0);
	}
}
