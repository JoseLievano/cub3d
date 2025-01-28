# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 15:06:36 by jlievano          #+#    #+#              #
#    Updated: 2024/06/08 20:50:11 by jlievano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	t_dll_new.c \
			t_dll_add_back.c \
			t_dll_add_front.c \
			t_dll_size.c \
			t_dll_get_head.c \
			t_dll_update_index.c \
			t_dll_get_node_index.c \
			t_dll_replace.c \
			t_dll_swap_nodes.c \
			t_dll_swap_side_nodes.c \
			t_dll_get_tail.c \
			t_dll_rotate.c \
			t_dll_r_rotate.c \
			t_dll_contains.c \
			t_dll_uqb.c \
			t_dll_uqf.c \
			t_dll_remove.c \
			t_dll_clear.c \
			t_dll_insert_a.c \
			t_dll_is_valid.c \
			t_dll_for_each.c \
			t_dll_clone_range.c \
			t_dll_move_to.c \
			t_dll_find_first_match.c

OBJS		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	t_dll.a

all:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
