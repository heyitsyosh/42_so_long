NAME = so_long

LIBFTDIR = ../lib/libft/
PRINTFDIR = ../lib/printf/
GNLDIR = ../lib/gnl/
MLXDIR = ../lib/mlx/

SRCS_ = so_long\
		check_args\
		read_map\
		check_map\
		check_map_pt_ii

SRCS = $(addsuffix .c, $(SRCS_))
OBJS = $(SRCS:.c=.o)

LIBFT = ../lib/libft/libft.a -I ../lib/libft
FT_PRINTF = ../lib/printf/libftprintf.a -I ../lib/printf
GNL = ../lib/gnl/get_next_line.a -I ../lib/gnl
SO_LONG = -I ./

CFLAGS = -Wall -Wextra -Werror

ifeq ($(MAKECMDGOALS),linux)
MLX = -I ../lib/mlx -L../lib/mlx -lmlx -lXext -lX11
else
MLX = -I ../lib/mlx -L/usr/X11R6/lib -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $^ $(SO_LONG) $(FT_PRINTF) $(LIBFT) $(GNL) $(MLX) -o $@

linux: all

bonus: all

clean:
	make fclean -C $(LIBFTDIR)
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus