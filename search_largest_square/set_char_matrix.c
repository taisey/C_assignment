/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:24:45 by yadachi           #+#    #+#             */
/*   Updated: 2021/03/10 22:46:28 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	set_char_matrix(char *str, char **matrix, int w_len, int h_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < h_len)
	{
		j = 0;
		while (j < w_len)
		{
			matrix[i][j] = *str;
			str++;
		}
		str++;
		i++;
	}
}

int		make_matrix(char **matrix, int w_len, int h_len)
{
	int	i;

	matrix = (char**)malloc(sizeof(char*) * w_len);
	if (!matrix)
		return (0);
	i = 0;
	while (i < w_len)
	{
		matrix[i] = (char*)malloc(sizeof(char) * h_len);
		if (!matrix[i])
			return (0);
		i++;
	}
	return (1);
}
