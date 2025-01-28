/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_for_each.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:59:58 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/22 15:01:42 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

void	t_dll_for_each(t_dll *node, void (*iterator)(t_dll *))
{
	node = t_dll_get_head(node);
	while (node)
	{
		iterator(node);
		node = node->next;
	}
}
