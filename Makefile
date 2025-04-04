NAME		=	philosophers

CFLAGS		=	-Wall -Werror -Wextra -Iincludes -g3

SRCS		=	src/utils.c src/philosophers.c src/parsing.c src/init.c src/dinner.c \
				src/destroy.c src/time.c src/routine.c src/monitor.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	= 	-I includes -I libft -I ft_printf

FT_PRINTF	=	ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re