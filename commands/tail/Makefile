SRCDIR = ./srcs
TARGET = ft_tail
SUFFIX =.c
SRCS = $(wildcard $(SRCDIR)/*$(SUFFIX))
OBJS = $(notdir $(SRCS:$(SUFFIX)=.o))

$(TARGET): $(OBJS)
	gcc $^ -o $@
	chmod 777 $@

$(OBJS): $(SRCS)
	gcc -c $^ -Wall -Wextra -Werror

clean:
	rm -r -f $(OBJS)

fclean: clean
	rm -r -f $(TARGET)

all : $(TARGET)
	