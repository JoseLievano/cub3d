/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_get_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:51:57 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/08 20:43:21 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_get_head(t_dll *node)
{
	t_dll	*head;

	if (!node)
		return (NULL);
	head = node;
	while (head->prev)
		head = head->prev;
	return (head);
}
