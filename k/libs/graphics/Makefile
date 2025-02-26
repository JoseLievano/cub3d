NAME		=	ft_graphics.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRC:.c=.o)
SRC			=	ft_graphics.c ft_graphics_init.c ft_draw_walls.c ft_gfx_utils.c

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re