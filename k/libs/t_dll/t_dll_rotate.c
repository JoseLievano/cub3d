/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:54 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/14 12:22:56 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	normal_rotate(t_dll *first, t_dll *second, t_dll *last)
{
	last->next = first;
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
}

void	t_dll_rotate(t_dll **head)
{
	t_dll	*first;
	t_dll	*second;
	t_dll	*last;
	size_t	dl_size;

	first = t_dll_get_head(*head);
	dl_size = t_dll_size(first);
	second = first->next;
	last = t_dll_get_tail(first);
	if (dl_size > 2)
	{
		normal_rotate (first, second, last);
		*head = second;
		t_dll_update_index(second);
	}
	if (dl_size == 2)
		t_dll_swap_nodes(0, 1, head);
}
