/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_move_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:49:00 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/11 22:44:47 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	move_to_tail(t_dll **list, long from_i)
{
	t_dll	*to_tail;
	t_dll	*actual_head;

	actual_head = t_dll_get_head(*list);
	to_tail = t_dll_remove(&actual_head, (size_t)from_i);
	t_dll_add_back(&actual_head, to_tail);
}

static void	move_to_head(t_dll **list, long from_i)
{
	t_dll	*to_head;
	t_dll	*actual_head;

	actual_head = t_dll_get_head(*list);
	to_head = t_dll_remove(&actual_head, (size_t)from_i);
	t_dll_add_front(&actual_head, to_head);
}

static void	move_forward(t_dll **list, long from_i, long to_i)
{
	t_dll	*temp;
	t_dll	*head;

	head = t_dll_get_head(*list);
	temp = t_dll_remove(&head, (size_t)from_i);
	t_dll_insert_a(&head, temp, (size_t)to_i - 1);
}

static void	move_backward(t_dll **list, long from_i, long to_i)
{
	t_dll	*temp;
	t_dll	*head;
	t_dll	*next;

	head = t_dll_get_head(*list);
	temp = t_dll_remove(&head, (size_t)from_i);
	if (to_i == 1)
		t_dll_insert_a(&head, temp, (size_t)to_i);
	else
	{
		next = t_dll_get_node_index(head, to_i);
		temp->next = next;
		temp->prev = next->prev;
		next->prev = temp;
		temp->prev->next = temp;
	}
}

void	t_dll_move_to(t_dll **list, long from_i, long to_i)
{
	t_dll	*tail;

	if (from_i == to_i)
		return ;
	tail = t_dll_get_tail(*list);
	if ((from_i < 0 || to_i < 0)
		|| (from_i > tail->index
			|| to_i > tail->index))
		return ;
	if (to_i == 0)
		move_to_head(list, from_i);
	else if (tail->index == to_i)
		move_to_tail(list, from_i);
	else
	{
		if (from_i > to_i)
			move_backward(list, from_i, to_i);
		else if (from_i < to_i)
			move_forward(list, from_i, to_i);
	}
	*list = t_dll_get_head(*list);
}
