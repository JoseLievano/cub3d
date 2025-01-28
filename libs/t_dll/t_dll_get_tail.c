/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_get_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:28:30 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/14 12:28:44 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_get_tail(t_dll *head)
{
	size_t	dl_size;

	head = t_dll_get_head(head);
	t_dll_update_index(head);
	dl_size = t_dll_size(head);
	if (dl_size == 0)
		return (NULL);
	if (dl_size == 1)
		return (head);
	return (t_dll_get_node_index(head, dl_size - 1));
}
