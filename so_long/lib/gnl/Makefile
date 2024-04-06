NAME = get_next_line.a

OBJSDIR = objs/
LIBFTDIR = ../libft/objs/

SRCS = get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:%.c=$(OBJSDIR)%.o)

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../../includes/

# **************************************************************************** #

all: $(NAME)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: %.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(LIBFTDIR)ft_strlen.o $(LIBFTDIR)ft_safe_free.o $(LIBFTDIR)ft_strchr.o $^

clean:
	${RM} -r $(OBJSDIR)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: clean fclean re all