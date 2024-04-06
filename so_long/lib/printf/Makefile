NAME = libftprintf.a

LIBFTDIR = ../libft

SRCS = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR),  $(addsuffix .o, $(SRCS)))

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../../includes

# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	make -C $(LIBFTDIR)
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re