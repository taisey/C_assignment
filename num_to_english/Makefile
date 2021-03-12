# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 00:42:24 by tyoshida          #+#    #+#              #
#    Updated: 2021/03/13 01:23:16 by taichika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_rush02

SOURCES	=	./main.c \
			./put.c \
			./search.c \
			./atoi.c \
			./ptr_digit.c\
			./check.c

OBJECTS	=	./main.o \
			./put.o \
			./search.o \
			./atoi.o \
			./ptr_digit.o \
			./check.o

FLAGS	=	-Werror -Wall -Wextra

HEADER	=	./header

$(NAME)		:	all

all			:
				gcc -c $(FLAGS) $(SOURCES) -I $(HEADER) 
				gcc -o $(NAME) $(FLAGS) $(OBJECTS)

clean		: 
				rm -rf $(OBJECTS)

fclean		:	clean
				rm -rf $(NAME)

re			:	
