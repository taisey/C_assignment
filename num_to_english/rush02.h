/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:03:42 by tyoshida          #+#    #+#             */
/*   Updated: 2021/03/13 02:50:58 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REF_H
# define FT_REF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUF_SIZE 30000

typedef unsigned int t_ui;

unsigned int	ft_recursive_power(unsigned int nb, int power);
void main_body(char *dict_name, char *arg);
void			ptr_three_digit(unsigned int num);
void			ptr_all_digit(unsigned int num, unsigned int digit, char *dict_name);
unsigned int	ft_atoi(char *str);
int				argument_is_valid(char *argv);
void			ft_putchar(char c);
void			ft_putnumber(unsigned int num);
void			ft_putstring(char *c);
void			ft_puterr(int i);
int				strcmp_partly(char *s1, char *s2);
char			*itoa(unsigned int nb, char *ans);
char			*strdup_to_indent(char *src);
char			*extract_value(char *line_head);
char			*search_key(char *dict, unsigned int key);
char			*search_dictionary(char *dict_name, unsigned int key);
int		shaping_line(char **dict, char **ans);
unsigned int	ft_atoi(char *str);
int				argument_is_valid(char *argv);
#endif
