/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:44:42 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/10 13:53:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:05:17 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/16 15:07:08 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_shift(t_dll **head)
{
	t_dll	*first_element;
	size_t	lst_size;

	first_element = t_dll_get_head(*head);
	lst_size = t_dll_size(first_element);
	if (lst_size == 0)
		return (NULL);
	if (lst_size == 1)
		return (first_element);
	*head = first_element->next;
	first_element->next->prev = NULL;
	first_element->next = NULL;
	first_element->prev = NULL;
	t_dll_update_index(*head);
	return (first_element);
}

t_dll	*t_dll_pop(t_dll *node)
{
	t_dll	*first_element;
	t_dll	*last_node;
	size_t	lst_size;

	first_element = t_dll_get_head(node);
	lst_size = t_dll_size(node);
	if (lst_size == 0)
		return (NULL);
	if (lst_size == 1)
		return (first_element);
	last_node = t_dll_get_tail(first_element);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = NULL;
	return (last_node);
}

static t_dll	*rm_node(t_dll *node)
{
	t_dll	*prev;
	t_dll	*next;

	prev = node->prev;
	next = node->next;
	prev->next = next;
	next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_dll	*t_dll_remove(t_dll **head, size_t index)
{
	t_dll	*first_element;
	t_dll	*removed_node;
	size_t	lst_size;

	first_element = t_dll_get_head(*head);
	lst_size = t_dll_size(first_element);
	if (index >= lst_size)
		return (NULL);
	if (lst_size == 1 && index == 0)
		return (first_element);
	if (lst_size > 1 && index == 0)
		removed_node = t_dll_shift(head);
	else if (lst_size > 1 && index == (lst_size - 1))
		removed_node = t_dll_pop(first_element);
	else
		removed_node = rm_node(t_dll_get_node_index(*head, index));
	t_dll_update_index(*head);
	return (removed_node);
}
