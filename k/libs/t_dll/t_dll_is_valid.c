/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:36:55 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/20 12:37:53 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

int	t_dll_is_valid(t_dll *node, int (*validator)(t_dll *node))
{
	node = t_dll_get_head(node);
	if (!node)
		return (0);
	while (node)
	{
		if (!validator(node))
			return (0);
		node = node->next;
	}
	return (1);
}
