/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:38:15 by taichika          #+#    #+#             */
/*   Updated: 2021/03/10 23:36:52 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char		*read_file(char *f_name)
{
	char	*buf;
	int		fd;
	int		rc;

	buf = (char*)malloc(30000);
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	rc = read(fd, buf, 30000);
	if (rc == -1)
	{
		close(fd);
		return (NULL);
	}
	return (buf);
}

t_map_info	*read_header(char *doc)
{
	char		*header;
	char		*header_origin;
	t_map_info	*map_info;
	char		**map;

	header = (char*)malloc(100);
	header_origin = header;
	while (*doc != '\n' && *doc != '\0')
	{
		*header = *doc;
		header++;
		doc++;
	}
	*header = '\0';
	header = header_origin;
	if (check_header(header_origin) == -1)
		return (NULL);
	map_info = (t_map_info*)malloc(sizeof(t_map_info));
	map_info->h_len = bsq_atoi(header, ft_strlen(header) - 3);
	map_info->charset = &header[ft_strlen(header) - 3];
	map = (char**)malloc(sizeof(char*) * map_info->h_len);
	map_info->map = map;
	return (map_info);
}

t_map_info	*buf_to_map(char *doc, t_map_info *map_info)
{
	char	**map;
	int		h;

	h = 0;
	map = map_info->map;
	while (h < map_info->h_len)
	{
		*map = ft_strdup(doc);
		h++;
		doc += ft_strlen(*map) + 1;
		map++;
	}
	map_info->w_len = ft_strlen(*(map_info->map));
	return (map_info);
}

t_map_info	*file_to_map(char *file_name)
{
	char		*doc;
	t_map_info	*map_info;

	doc = read_file(file_name);
	if (doc == NULL)
		return (NULL);
	if (!check_first_col(doc))
		return (NULL);
	map_info = read_header(doc);
	while (*doc != '\n')
		doc++;
	doc++;
	if (buf_check(doc, map_info))
		return (NULL);
	buf_to_map(doc, map_info);
	return (map_info);
}
