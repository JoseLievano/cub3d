/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_swap_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:08:53 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/09 01:16:54 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	rewire(t_dll *prev, t_dll *node, t_dll *next)
{
	if (prev)
	{
		prev->next = node;
		node->prev = prev;
	}
	else
		node->prev = prev;
	if (next)
	{
		next->prev = node;
		node->next = next;
	}
	else
		node->next = next;
}

static void	modify_head(t_dll **head, t_dll *temp1, t_dll *temp2)
{
	if (!temp1->prev)
	{
		*head = temp2;
		return ;
	}
	if (!temp2->prev)
		*head = temp1;
}

static int	input_validator(size_t index1, size_t index2, t_dll *head)
{
	if (!head)
		return (0);
	if (index1 >= t_dll_size(head) || index2 >= t_dll_size(head))
		return (0);
	if (index1 == index2)
		return (0);
	return (1);
}

void	t_dll_swap_nodes(size_t index1, size_t index2, t_dll **head)
{
	t_dll	*temp1;
	t_dll	*temp1_next;
	t_dll	*temp1_prev;
	t_dll	*temp2;
	t_dll	*temp2_lst[2];

	if (!input_validator(index1, index2, *head))
		return ;
	temp1 = t_dll_get_node_index(*head, index1);
	temp2 = t_dll_get_node_index(*head, index2);
	temp1_next = temp1->next;
	temp1_prev = temp1->prev;
	temp2_lst[1] = temp2->next;
	temp2_lst[0] = temp2->prev;
	modify_head(head, temp1, temp2);
	if (!t_dll_swap_side_nodes(temp1, temp2))
	{
		rewire(temp2_lst[0], temp1, temp2_lst[1]);
		rewire(temp1_prev, temp2, temp1_next);
	}
	t_dll_update_index(*head);
}
