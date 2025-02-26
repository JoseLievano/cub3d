/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:46:58 by jlievano          #+#    #+#             */
/*   Updated: 2024/07/14 12:33:37 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

void	t_dll_add_front(t_dll **list, t_dll *new_node)
{
	if (!list || !new_node)
		return ;
	new_node->prev = NULL;
	new_node->next = *list;
	if (*list)
		(*list)->prev = new_node;
	*list = new_node;
	t_dll_update_index(new_node);
}
