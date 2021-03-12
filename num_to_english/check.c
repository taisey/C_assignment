/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:24 by taichika          #+#    #+#             */
/*   Updated: 2021/03/13 02:57:15 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "rush02.h"

int		shaping_line(char **dict, char **ans)
{
	while (**dict != ':')
	{
		**ans = **dict;
		*ans += 1;
		*dict += 1;
	}
	*ans -= 1;
	while (**ans == ' ' || **ans == '\t' || **ans == '\r'
		|| **ans == '\v' || **ans == '\f')
		*((*ans)--) = '\0';
	*ans += 1;
	*((*ans)++) = *((*dict)++);
	while (**dict == ' ' || **dict == '\t'
		|| **dict == '\r' || **dict == '\v' || **dict == '\f')
		*dict += 1;
	while (**dict != '\n')
	{
		if (**dict == '\0')
			return (0);
		*((*ans)++) = *((*dict)++);
	}
	*((*ans)++) = *((*dict)++);
	return (1);
}

char	*shaping_dictionary(char *dict)
{
	char *ans;
	char *ans_origin;
	char *num_str;

	num_str = (char*)malloc(1000);
	ans = (char*)malloc(30000);
	ans_origin = ans;
	while (*dict != '\0')
	{
		if (*dict == '\n')
			continue;
		else
		{
			while (*dict == ' ' || *dict == '\t'
				|| *dict == '\r' || *dict == '\v' || *dict == '\f')
				dict += 1;
			if (*dict == ':')
				return (0);
			if (shaping_line(&dict, &ans) == 0)
				return (0);
		}
	}
	return (ans_origin);
}
