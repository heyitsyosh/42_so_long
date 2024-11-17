NAME = libftprintf.a

OBJS_DIR = objs
LIBFT_DIR = ../libft

SRCS = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SRCS)))

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../../includes/

GREEN = \033[0;32m
NC = \033[0m

# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "$(GREEN)Entering libft directory...$(NC)\n"
	@make -C $(LIBFT_DIR)
	@printf "$(GREEN)Entering ft_printf directory...$(NC)\n"
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	@printf "$(GREEN)Entering libft directory...$(NC)\n"
	@make fclean -C $(LIBFT_DIR)
	@printf "$(GREEN)Entering ft_printf directory...$(NC)\n"
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
