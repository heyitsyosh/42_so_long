NAME         := get_next_line.a

CC           := cc
CFLAGS       := -Wall -Wextra -Werror
INCLUDES     := -I ../../includes/

OBJS_DIR     := objs
LIBFTOBJS_DIR := ../libft/objs

SRCS         := get_next_line get_next_line_utils
OBJS         := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SRCS)))

# **************************************************************************** #

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ \
		$(LIBFTOBJS_DIR)/ft_strlen.o \
		$(LIBFTOBJS_DIR)/ft_safe_free.o \
		$(LIBFTOBJS_DIR)/ft_strchr.o \
		$^

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
