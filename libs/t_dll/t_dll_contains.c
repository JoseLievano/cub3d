/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_contains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:48 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/15 19:41:50 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

long	t_dll_contains(t_dll *h, t_dll *nd, int (*c)(t_dll *, t_dll *))
{
	size_t	list_size;
	t_dll	*real_head;

	real_head = t_dll_get_head(h);
	if (!real_head)
		return (-1);
	list_size = t_dll_size(real_head);
	if (list_size == 0)
		return (-1);
	if (list_size == 1)
	{
		if (c(real_head, nd))
			return (h->index);
		else
			return (-1);
	}
	while (real_head)
	{
		if (c(real_head, nd))
			return (real_head->index);
		real_head = real_head->next;
	}
	return (-1);
}
