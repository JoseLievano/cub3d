/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:57:15 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/08 20:47:20 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

size_t	t_dll_size(t_dll *list)
{
	size_t	i;
	t_dll	*head;

	head = t_dll_get_head(list);
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
