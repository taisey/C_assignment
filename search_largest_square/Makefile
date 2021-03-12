CC = gcc
CFLAGS = -Wall -Werror -Wextra
SUFFIX = .c
TARGET = bsq
SRCS = $(wildcard *$(SUFFIX))
OBJS = $(notdir $(SRCS:$(SUFFIX)=.o))
INCLUDE = ./includes

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $@ -I $(INCLUDE)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDE)

clean:
	rm -f -r $(OBJS)

fclean: clean
	rm  -f -r $(TARGET)

re: fclean all
