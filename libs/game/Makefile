NAME	=	ft_game.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRC:.c=.o)
SRC		=	ft_game.c

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
