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
BONUS_FILES = $(FILES) spawn_enemy enemy

OBJS = $(addprefix $(OBJSDIR), $(addsuffix .o, $(FILES)))
B_OBJS = $(addprefix $(OBJSDIR), $(addsuffix _bonus.o, $(BONUS_FILES)))

OBJSDIR = objs/
LIBFTDIR = ./lib/libft/
PRINTFDIR = ./lib/printf/
GNLDIR = ./lib/gnl/
MLXDIR = ./lib/minilibx-linux/

ifeq ($(MAKECMDGOALS),bonus)
OBJS = $(B_OBJS)
SRCSDIR = bonus/
else
SRCSDIR = mandatory/
endif

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a 

CFLAGS = -Wall -Wextra -Werror -I ./includes
DEFINE_KEYS = -D $(ESC) -D $(W) -D $(A) -D $(S) -D $(D) -D $(FRAMERATE) -D $(ADJUST)

#--------------------------------------------------------------------------#

OS = $(shell uname -s)

ifeq ($(OS),Linux)
ESC = ESC=65307
W = W=119
A = A=97
S = S=115
D = D=100
FRAMERATE = FRAMERATE=1000
ADJUST = ADJUST=0
MLX = -I $(MLXDIR) -L$(MLXDIR) -lmlx -lXext -lX11 $(MLXDIR)libmlx.a
else
ESC = ESC=53
W = W=13
A = A=0
S = S=1
D = D=2
FRAMERATE = FRAMERATE=700
ADJUST = ADJUST=20
MLX = -I $(MLXDIR) -L/usr/X11R6/lib -lmlx -lXext -lX11 -framework OpenGL -framework Appkit $(MLXDIR)libmlx_Darwin.a
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FT_PRINTF) $(GNL) $(MLX)

$(OBJSDIR)%.o: $(SRCSDIR)%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(DEFINE_KEYS) -c -o $@ $<

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

bonus: all

clean:
	make clean -C $(PRINTFDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	$(RM) -r $(OBJSDIR)

fclean: clean
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
