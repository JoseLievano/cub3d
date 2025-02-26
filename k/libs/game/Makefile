NAME	=	ft_game.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRC:.c=.o)
SRC		=	ft_game.c ft_game_init.c ft_game_over.c ft_input_functions.c \
			ft_game_loop.c ft_move_player.c ft_walk.c ft_init_player.c

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
