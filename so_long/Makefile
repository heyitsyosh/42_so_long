NAME = so_long

SRCS_ = so_long\
		check_args\
		read_map\
		skip_map\
		extract_map\
		check_parsed_map
#		check_valid_path\

OBJS = $(SRCS:.c=.o)

OBJDIR = ./srcs/mandatory/objs
LIBFTDIR = ./lib/libft/
PRINTFDIR = ./lib/printf/
GNLDIR = ./lib/gnl/
MLXDIR = ./lib/mlx/

FT_PRINTF = ./lib/printf/libftprintf.a
GNL = ./lib/gnl/get_next_line.a

CFLAGS = -Wall -Wextra -Werror -I ./includes

ifeq ($(MAKECMDGOALS),bonus)
SRCS = $(foreach src,$(SRCS_),./srcs/bonus/$(src)_bonus.c)
OBJDIR = ./srcs/bonus/objs
else
SRCS = $(foreach src,$(SRCS_),./srcs/mandatory/$(src).c)
endif

ifeq ($(MAKECMDGOALS),linux)
MLX = -I ./lib/mlx -L./lib/mlx -lmlx -lXext -lX11
else
MLX = -I ./lib/mlx -L/usr/X11R6/lib -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(GNL) $(MLX) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

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