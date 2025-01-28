/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_swap_side_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:17:14 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/14 09:17:17 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	side_swap(t_dll *node1, t_dll *node2)
{
	t_dll	*node_prev;
	t_dll	*node_next;

	node_prev = node1->prev;
	node_next = node2->next;
	node2->next = node1;
	node1->prev = node2;
	if (node_prev)
	{
		node2->prev = node_prev;
		node_prev->next = node2;
	}
	else
		node2->prev = NULL;
	if (node_next)
	{
		node1->next = node_next;
		node_next->prev = node1;
	}
	else
		node1->next = NULL;
}

int	t_dll_swap_side_nodes(t_dll *nd1, t_dll *nd2)
{
	if ((nd1->index + 1) == nd2->index || (nd2->index + 1) == nd1->index)
	{
		if (nd1->index < nd2->index)
			side_swap(nd1, nd2);
		else
			side_swap(nd2, nd1);
		return (1);
	}
	return (0);
}
