NAME = so_long

SRCS_ = so_long\
		check_args\
		read_map\
		skip_map\
		extract_map\
		check_parsed_map\
		check_valid_path\

SRCS = $(addsuffix .c, $(SRCS_))
OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./lib/libft/
PRINTFDIR = ./lib/printf/
GNLDIR = ./lib/gnl/
MLXDIR = ./lib/mlx/

FT_PRINTF = ./lib/printf/libftprintf.a
GNL = ./lib/gnl/get_next_line.a

CFLAGS = -Wall -Wextra -Werror -I ./includes

ifeq ($(MAKECMDGOALS),linux)
MLX = -I ./lib/mlx -L./lib/mlx -lmlx -lXext -lX11
else
MLX = -I ./lib/mlx -L/usr/X11R6/lib -lmlx -lXext -lX11
endif

ifeq ($(MAKECMDGOALS),bonus)
SRCS = $(addsuffix _bonus.c, $(SRCS_))
endif

all: $(NAME)

$(NAME): $(SRCS)
	$(make) -C $(PRINTFDIR)
	$(make) -C $(GNLDIR)
	$(make) -C $(MLXDIR)
	$(CC) $(CFLAGS) $^ $(SO_LONG) $(FT_PRINTF) $(LIBFT) $(GNL) $(MLX) -o $@

linux: all

bonus: all

clean:
	$(make) clean -C $(PRINTFDIR)
	$(make) clean -C $(GNLDIR)
	$(make) clean -C $(MLXDIR)

fclean: clean
	$(make) fclean -C $(PRINTFDIR)
	$(make) fclean -C $(GNLDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus