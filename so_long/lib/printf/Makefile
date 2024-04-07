NAME = libftprintf.a

OBJS_DIR = objs/
LIBFT_DIR = ../libft/

SRCS = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags
OBJS = $(addprefix $(OBJS_DIR),  $(addsuffix .o, $(SRCS)))

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../../includes/

# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	make -C $(LIBFT_DIR)
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
