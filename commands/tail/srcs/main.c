/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:34:04 by taichika          #+#    #+#             */
/*   Updated: 2021/03/14 00:31:05 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define BUF_SIZE 30000

void	ptr_exception(char *argv)
{
	char *error;

	write(1, "tail: ", 5);
	while (*argv != '\0')
	{
		write(1, argv, 1);
		argv++;
	}
	write(1, ": ", 2);
	error = strerror(errno);
	while (*error != '\0')
	{
		write(1, error, 1);
		error++;
	}
}

int		main_body(char *arg, int argc)
{
	int f;

	f = open(arg, O_RDONLY);
	if (f == -1)
	{
		ptr_exception(arg);
		return (-1);
	}
	if (argc > 4)
	{
		write(1, "==> ", 4);
		while (*arg != '\0')
			write(1, arg++, 1);
		write(1, " <==\n", 5);
	}
	return (f);
}

char	*tail_body(char *buf, int n)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	buf = (i >= n ? buf + (i - n) : buf);
	while (*buf != '\0')
	{
		write(1, buf, 1);
		buf++;
	}
	return (buf);
}

int		ft_atoi(char *str)
{
	int diff;
	int ans;

	if (*str == '-')
		str++;
	ans = 0;
	diff = '0' - 0;
	while (ans < 1000000000)
	{
		if (*str < '0' || *str > '9')
		{
			return (ans);
		}
		ans *= 10;
		ans += (int)(*str - diff);
		str++;
	}
	return (ans);
}

int		main(int argc, char *argv[])
{
	int		f;
	char	*buf;
	int		i;
	int		n;
	int		dif;

	buf = (char*)malloc(BUF_SIZE);
	i = 2;
	n = ft_atoi(argv[2]);
	if (argc < 2)
		while (1)
			;
	else
	{
		while (i++ < argc - 1)
		{
			f = main_body(argv[i], argc);
			if (f == -1)
				return (0);
			dif = read(f, buf, BUF_SIZE);
			buf = tail_body(buf, n);
			if (argc != 4 && i != argc - 1)
				write(1, "\n", 1);
		}
	}
}
