/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:34:04 by taichika          #+#    #+#             */
/*   Updated: 2021/03/05 00:34:49 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

# define BUF_SIZE 30000

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void buf_init(char *buf, int buf_size)
{
	int i;

	i = 0;
	while(i < buf_size)
	{
		buf[i] = '\0';
		i++;
	}
}

void ptr_exception(char *argv)
{
	write(1, "cat: ",5);
	ft_putstr(argv);
	write(1, ": ",2);
	ft_putstr((strerror(errno)));
	write(1, "\n",1);
}

int main(int argc, char *argv[])
{
	int f;
	char buf[BUF_SIZE];
	int i;
	
	i = 1;
	if(argc < 2)
		while(1);
	else{
		while(i < argc)
		{
			buf_init(buf, BUF_SIZE);
			f = open(argv[i], O_RDONLY);
			if (f == -1)
			{
				ptr_exception(argv[i]);
				return (0);
			}
			read(f, buf, BUF_SIZE);
			ft_putstr(buf);
			i++;
		}
	}
}
