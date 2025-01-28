/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:17:21 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/08 20:46:18 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_new(void *content)
{
	t_dll	*new_element;

	new_element = (t_dll *)malloc(sizeof(t_dll));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->index = 0;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}
