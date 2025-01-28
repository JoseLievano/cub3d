/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:01 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/14 12:23:03 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	reverse_rotate(t_dll *first, t_dll *penultimate, t_dll *last)
{
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	penultimate->next = NULL;
}

void	t_dll_r_rotate(t_dll **head)
{
	t_dll	*first;
	t_dll	*penultimate;
	t_dll	*last;
	size_t	dl_size;

	first = t_dll_get_head(*head);
	dl_size = t_dll_size(first);
	last = t_dll_get_tail(first);
	penultimate = last->prev;
	if (dl_size > 2)
	{
		reverse_rotate(first, penultimate, last);
		*head = last;
		t_dll_update_index(last);
	}
	else if (dl_size == 2)
		t_dll_swap_nodes(0, 1, head);
}
