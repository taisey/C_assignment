/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:27:53 by taichika          #+#    #+#             */
/*   Updated: 2021/03/13 02:55:18 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

char	*itoa(unsigned int nb, char *ans)
{
	unsigned int	div;
	unsigned int	mod;
	char			*current;

	if (nb < 10)
	{
		*ans = '0' + nb;
		return (ans + 1);
	}
	div = nb / 10;
	mod = nb % 10;
	current = itoa(div, ans);
	*current = '0' + mod;
	return (current + 1);
}

char	*strdup_to_indent(char *src)
{
	char		*dest;
	char		*output;
	char		*src_for_cnt;
	int			cnt;

	src_for_cnt = src;
	cnt = 0;
	while (*(src_for_cnt++) != '\n')
		cnt++;
	dest = (char*)malloc(cnt + 1);
	if (dest == NULL)
		return (NULL);
	output = dest;
	while (*src != '\n')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (output);
}

char	*extract_value(char *line_head)
{
	while (*line_head != ':')
		line_head++;
	line_head++;
	while (*line_head == ' ' || *line_head == '\r' || *line_head == '\f'
		|| *line_head == '\t' || *line_head == '\v')
		line_head++;
	return (strdup_to_indent(line_head));
}

char	*search_key(char *dict, unsigned int key)
{
	char *key_str;
	char *key_str_tail;

	key_str = malloc(100);
	key_str_tail = itoa(key, key_str);
	*key_str_tail = '\0';
	while (*dict != '\0')
	{
		if (*dict == '\n')
			dict++;
		if (strcmp_partly(key_str, dict) == 0)
		{
			return (extract_value(dict));
		}
		else
		{
			while (*dict != '\n' && *dict != '\0')
				dict++;
		}
	}
	return (NULL);
}

char	*search_dictionary(char *dict_name, unsigned int key)
{
	int			f;
	char		buf[BUF_SIZE];
	char		*ans;

	f = open(dict_name, O_RDONLY);
	if (f == -1)
	{
		ft_puterr(0);
		return (NULL);
	}
	read(f, buf, BUF_SIZE);
	ans = search_key(buf, key);
	if (ans == NULL)
		ft_puterr(0);
	return (ans);
}
