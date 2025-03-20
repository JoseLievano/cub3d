NAME		=	ft_parse.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRC:.c=.o)
SRC			=	check_text.c \
				create_map.c \
				errors.c \
				fill_color_text.c \
				ft_parse_utils.c \
				init_map.c \
				init_textures.c \
				main.c \
				map_borders.c \
				map_parser.c \
				map_loader.c \
				parse_args.c

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
