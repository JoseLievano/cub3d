NAME		=	ft_raycast.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRC:.c=.o)
SRC			=	ft_raycast.c ft_dda.c ft_init_ray.c

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
