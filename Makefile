CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	cube3d
OBJS		=	$(SRC:.c=.o)
MINILIBX	=	libs/minilibx/libmlx_Linux.a
LIBFT		=	libs/libft/libft.a
T_DLL		=	libs/t_dll/t_dll.a
PARSE		=	libs/parse/ft_parse.a
GRAPHICS	=	libs/graphics/ft_graphics.a
GAME		=	libs/game/ft_game.a
INPUT		=	libs/input/ft_input.a
RAYCAST		=	libs/raycast/ft_raycast.a
UTILS		=	libs/utils/ft_utils.a
SRC_DIR		=	src/
SRC_FILES	=	cub3d.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

all			:	$(NAME)

$(NAME)		:	download $(OBJS) $(GAME) $(GRAPHICS) $(RAYCAST) $(INPUT) $(PARSE) $(UTILS) $(T_DLL) $(LIBFT) $(MINILIBX)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GAME) $(GRAPHICS) $(RAYCAST) $(INPUT) $(PARSE) $(UTILS) $(T_DLL) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm

$(MINILIBX)	:
				$(MAKE) -C libs/minilibx/
$(T_DLL)	:
				$(MAKE) -C libs/t_dll/
$(LIBFT)	:
				$(MAKE) -C libs/libft
$(PARSE)	:
				$(MAKE) -C libs/parse
$(GRAPHICS)	:
				$(MAKE) -C libs/graphics
$(GAME)		:
				$(MAKE) -C libs/game
$(INPUT)	:
				$(MAKE) -C libs/input
$(RAYCAST)	:
				$(MAKE) -C libs/raycast
$(UTILS)	:
				$(MAKE) -C libs/utils

download	:
				@clear
				@rm -rf libs/minilibx
				@git clone git@github.com:42Paris/minilibx-linux.git libs/minilibx
				@clear

clean		:
				$(RM) $(OBJS)
				@make -C libs/t_dll clean
				@make -C libs/libft clean
				@make -C libs/parse clean
				@make -C libs/graphics clean
				@make -C libs/game clean
				@make -C libs/input clean
				@make -C libs/raycast clean
				@make -C libs/utils clean

fclean		:	clean
				@$(RM) $(NAME)
				@make -C libs/t_dll fclean
				@make -C libs/libft fclean
				@make -C libs/parse fclean
				@make -C libs/graphics fclean
				@make -C libs/game fclean
				@make -C libs/input fclean
				@make -C libs/raycast fclean
				@make -C libs/utils fclean

re			:	fclean all

.PHONY		:	all clean fclean re download
