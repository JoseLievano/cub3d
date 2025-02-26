/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll.h											 :+:	 :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:08:02 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/09 00:00:02 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DLL_H
# define T_DLL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//Double linked list struct
typedef struct init_t_dll
{
	void				*content;
	long				index;
	struct init_t_dll	*prev;
	struct init_t_dll	*next;
}	t_dll;

t_dll	*t_dll_new(void *content);
void	t_dll_add_front(t_dll **list, t_dll *new_node);
int		t_dll_uqf(t_dll **h, t_dll *n, int (*c)(t_dll *, t_dll *));
void	t_dll_add_back(t_dll **list, t_dll *new_node);
int		t_dll_uqb(t_dll **h, t_dll *n, int (*c)(t_dll *, t_dll *));
size_t	t_dll_size(t_dll *list);
int		t_dll_update_index(t_dll *node);
t_dll	*t_dll_get_head(t_dll *node);
t_dll	*t_dll_get_tail(t_dll *node);
t_dll	*t_dll_get_node_index(t_dll *node, size_t index);
t_dll	*t_dll_replace(size_t index, t_dll *head, t_dll *new_node);
void	t_dll_swap_nodes(size_t index1, size_t index2, t_dll **head);
int		t_dll_swap_side_nodes(t_dll *node1, t_dll *node2);
void	t_dll_rotate(t_dll **head);
void	t_dll_r_rotate(t_dll **head);
long	t_dll_contains(t_dll *h, t_dll *n, int (*c)(t_dll *, t_dll *));
t_dll	*t_dll_remove(t_dll **head, size_t index);
t_dll	*t_dll_shift(t_dll **head);
t_dll	*t_dll_pop(t_dll *node);
void	t_dll_clear(t_dll *node, void (*n_clear)(t_dll*));
void	t_dll_insert_a(t_dll **head, t_dll *new_node, size_t index);
int		t_dll_is_valid(t_dll *node, int (*validator)(t_dll *node));
void	t_dll_for_each(t_dll *node, void (*iterator)(t_dll *node));
t_dll	*t_dll_clone_range(t_dll *n, size_t s, size_t e, t_dll *(*c)(t_dll *n));
t_dll	*t_dll_clone(t_dll *n, t_dll *(*clone)(t_dll *n));
void	t_dll_move_to(t_dll **list, long from_i, long to_i);
t_dll	*t_dll_first_mtch(t_dll *l, void **a, int n, int (*c)(void **a, int n));
#endif
