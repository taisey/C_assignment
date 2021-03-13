SRCDIR = ./srcs
TARGET = ft_cat
SUFFIX =.c
SRCS = $(wildcard $(SRCDIR)/*$(SUFFIX))
OBJS = $(notdir $(SRCS:$(SUFFIX)=.o))

$(TARGET): $(SRCS)
	gcc $^ -o $@
	chmod 777 $@

$(OBJS): $(SRCS)
	gcc -c $^ -Wall -Wextra -Werror

clean:
	rm -r -f $(OBJS)

fclean: clean
	rm -r -f $(TARGET)
	
all : $(TARGET)