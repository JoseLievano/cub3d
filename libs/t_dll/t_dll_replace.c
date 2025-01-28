/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:29:31 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/09 20:30:30 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	replace_prev(t_dll *temp_node, t_dll *new_node)
{
	t_dll	*to_return_prev_node;

	to_return_prev_node = temp_node->prev;
	if (to_return_prev_node)
	{
		to_return_prev_node->next = new_node;
		new_node->prev = to_return_prev_node;
	}
}

static void	replace_next(t_dll *temp_node, t_dll *new_node)
{
	t_dll	*to_return_next_node;

	to_return_next_node = temp_node->next;
	if (to_return_next_node)
	{
		to_return_next_node->prev = new_node;
		new_node->next = to_return_next_node;
	}
}

t_dll	*t_dll_replace(size_t index, t_dll *head, t_dll *new_node)
{
	t_dll	*temp_node;
	size_t	list_size;

	list_size = t_dll_size(head);
	if (index >= list_size || !new_node || !head)
		return (NULL);
	temp_node = t_dll_get_node_index(head, index);
	replace_next(temp_node, new_node);
	replace_prev(temp_node, new_node);
	t_dll_update_index(head);
	return (temp_node);
}
