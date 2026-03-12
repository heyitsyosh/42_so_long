NAME := so_long

CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I ./includes/

OBJS_DIR := objs
PRINTF_DIR := ./lib/printf
GNL_DIR := ./lib/gnl
MLX_DIR := ./lib/minilibx-linux

FT_PRINTF := $(PRINTF_DIR)/libftprintf.a
GNL := ./lib/gnl/get_next_line.a

FILES := so_long \
        check_args \
        get_map \
        skip_map \
        extract_map \
        check_parsed_map \
        map_parse_utils \
        check_if_playable \
        start_game \
        images \
        key_action \
        key_action_utils \
        animation \
        spawn_enemy \
        enemy \
        close_game
OBJS := $(foreach obj, $(FILES), $(OBJS_DIR)/$(obj).o)

GREEN := \033[0;32m
NC := \033[0m

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
MLX = -I $(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 $(MLX_DIR)/libmlx.a
else
ESC = ESC=53
W = W=13
A = A=0
S = S=1
D = D=2
FRAMERATE = FRAMERATE=700
ADJUST = ADJUST=20
MLX = -I $(MLX_DIR) -L/usr/X11R6/lib -lmlx -lXext -lX11 -framework OpenGL -framework Appkit $(MLX_DIR)/libmlx_Darwin.a
endif

DEFINE_KEYS := -D $(ESC) -D $(W) -D $(A) -D $(S) -D $(D) -D $(FRAMERATE) -D $(ADJUST)

#--------------------------------------------------------------------------#

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: ./srcs/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_KEYS) -c -o $@ $<

$(NAME): $(OBJS)
	@printf "$(GREEN)Entering printf directory...$(NC)\n"
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@$(MAKE) --no-print-directory -C $(GNL_DIR)
	@printf "$(GREEN)Entering mlx directory...$(NC)\n"
	@$(MAKE) --no-print-directory -C $(MLX_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(FT_PRINTF) $(GNL) $(MLX)

clean:
	@printf "$(GREEN)Entering printf directory...$(NC)\n"
	@$(MAKE) clean --no-print-directory -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@$(MAKE) clean --no-print-directory -C $(GNL_DIR)
	@printf "$(GREEN)Entering mlx directory...$(NC)\n"
	@$(MAKE) clean --no-print-directory -C $(MLX_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	rm -rf $(OBJS_DIR)

fclean: clean
	@printf "$(GREEN)Entering printf directory...$(NC)\n"
	@$(MAKE) --no-print-directory fclean -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@$(MAKE) --no-print-directory fclean -C $(GNL_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
