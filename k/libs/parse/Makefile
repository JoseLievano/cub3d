NAME		=	ft_parse.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRC:.c=.o)
SRC			=	ft_parse.c ft_validator.c ft_get_next_line.c ft_get_next_line_tools.c \
				ft_holder_cleaner.c ft_params_validator.c ft_validator_utils.c \
				ft_get_textures.c ft_process_map.c ft_colors.c ft_file_key.c \
				ft_get_grid_content.c ft_get_grid.c ft_validate_grid.c

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
