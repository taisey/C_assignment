/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:16:57 by taichika          #+#    #+#             */
/*   Updated: 2021/03/13 02:57:52 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned int	ft_recursive_power(unsigned int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (ft_recursive_power(nb, power - 1) * nb);
}

void			ptr_three_digit(unsigned int num)
{
	unsigned int n[3];

	n[0] = num / 100;
	n[1] = num % 100 / 10;
	n[2] = num % 10;
	if (n[0] != 0)
	{
		ft_putstring(search_dictionary("number.dict", n[0]));
		write(1, " ", 1);
		ft_putstring(search_dictionary("number.dict", 100));
		write(1, " ", 1);
	}
	if (n[1] != 0)
	{
		ft_putstring(
			search_dictionary("number.dict",
			n[1] * 10 + (n[1] == 1 ? n[2] : 0)));
		write(1, " ", 1);
	}
	if (n[1] != 1 && (n[2] != 0 || (n[1] == 0 && n[0] == 0)))
	{
		ft_putstring(search_dictionary("number.dict", n[2]));
		write(1, " ", 1);
	}
}

void			ptr_all_digit(t_ui num, t_ui digit, char *dict_name)
{
	unsigned int	div_mod[2];
	char			*ans;

	if (num == 0)
	{
		if (digit == 0)
			ptr_three_digit(0);
		return ;
	}
	div_mod[0] = num / 1000;
	div_mod[1] = num % 1000;
	ptr_all_digit(div_mod[0], digit + 3, dict_name);
	if (div_mod[1] != 0)
		ptr_three_digit(div_mod[1]);
	if (digit != 0)
	{
		ans = search_dictionary(dict_name,
		ft_recursive_power(10, digit));
		if (ans == NULL)
			return (ft_puterr(0));
		ft_putstring(ans);
		write(1, " ", 1);
	}
	else
		write(1, "\n", 1);
}
