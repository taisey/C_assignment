/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadachi <yadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:02:57 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 23:29:28 by yadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	char_check(char c, char *charset)
{
	if (c == charset[0] || c == charset[1])
		return (0);
	return (-1);
}

int	buf_check(char *buf, t_map_info *map_info)
{
	int cnt;
	int tmp_cnt;

	cnt = -1;
	while (*buf != '\0')
	{
		tmp_cnt = 0;
		while (*buf != '\n' && *buf != '\0')
		{
			if (char_check(*buf, map_info->charset) == -1)
				return (-1);
			tmp_cnt++;
			buf++;
		}
		if (cnt != -1 && tmp_cnt != cnt)
			return (-1);
		cnt = tmp_cnt;
		if (*buf == '\0')
			break ;
		buf++;
	}
	return (0);
}

int	check_header(char *header)
{
	char	*charset;

	if (bsq_atoi(header, ft_strlen(header) - 3) == 0)
		return (-1);
	charset = &header[ft_strlen(header) - 3];
	if (charset[0] == '\0' || charset[1] == '\0'
		|| charset[2] == '\0' || ft_strlen(charset) != 3)
		return (-1);
	if (charset[0] == charset[1] || charset[1] == charset[2]
		|| charset[0] == charset[2])
		return (-1);
	return (0);
}
