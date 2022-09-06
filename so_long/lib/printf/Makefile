NAME = libftprintf.a

LIBFTDIR = ../libft

SRCS_ = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags

SRCS = $(addsuffix .c, $(SRCS_))
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus