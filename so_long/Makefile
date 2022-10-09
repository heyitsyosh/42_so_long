NAME = so_long

FILES = so_long\
		check_args\
		get_map\
		skip_map\
		extract_map\
		check_parsed_map\
		map_parse_utils\
		check_if_playable\
		start_game\
		images\
		key_action\
		key_action_utils\
		animation\
		close_game
SRCS = $(foreach src,$(FILES),./mandatory/$(src).c)
BONUS_FILES = $(FILES) spawn_enemy enemy
BONUS_SRCS = $(foreach bonus_src,$(BONUS_FILES),./bonus/$(bonus_src)_bonus.c)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS

OS = $(shell uname -s)

ifeq ($(OS),Linux)
ESC = 65307
W = 119
A = 97
S = 115
D = 100
FRAMERATE = 1000
MLX = -I $(MLXDIR) -L$(MLXDIR) -lmlx -lXext -lX11
else
ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
FRAMERATE = 200
MLX = -I $(MLXDIR) -L/usr/X11R6/lib -lmlx -lXext -lX11
endif

LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/printf
GNLDIR = ./lib/gnl
MLXDIR = ./lib/mlx

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a 

CFLAGS = -Wall -Wextra -Werror -I ./includes
DEFINE_KEYS = -D $(ESC) -D $(W) -D $(A) -D $(S) -D $(D) -D $(FRAMERATE)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $(DEFINE_KEYS) -o $@ $(OBJS) $(FT_PRINTF) $(GNL) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: all

clean:
	make clean -C $(PRINTFDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus linux