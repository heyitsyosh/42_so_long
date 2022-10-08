NAME = so_long

SRCS_ = so_long\
		check_args\
		get_map\
		skip_map\
		extract_map\
		check_parsed_map\
		map_parse_utils\
		check_valid_path\
		start_game\
		images\
		key_action\
		key_action_utils\
		animation\
		close_game

ifeq ($(MAKECMDGOALS),bonus)
SRCS = $(foreach src,$(SRCS_),./bonus/$(src)_bonus.c)
SRCS += ./bonus/enemy_bonus.c
else
SRCS = $(foreach src,$(SRCS_),./mandatory/$(src).c)
endif

OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/printf
GNLDIR = ./lib/gnl
MLXDIR = ./lib/mlx

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a 

CFLAGS = -Wall -Wextra -Werror -I ./includes

ifeq ($(MAKECMDGOALS),linux)
MLX = -I $(MLXDIR) -L$(MLXDIR) -lmlx -lXext -lX11
else
MLX = -I $(MLXDIR) -L/usr/X11R6/lib -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FT_PRINTF) $(GNL) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

linux: all

bonus: all

clean:
	make clean -C $(PRINTFDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus linux