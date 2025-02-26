/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_uqf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:01:36 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/15 12:01:37 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

int	t_dll_uqf(t_dll **head, t_dll *nn, int (*cmp)(t_dll *, t_dll *))
{
	t_dll	*first_element;
	long	contains_result;

	if (!*head)
	{
		*head = nn;
		return (1);
	}
	first_element = t_dll_get_head(*head);
	contains_result = t_dll_contains(first_element, nn, cmp);
	if (contains_result >= 0)
		return (0);
	else
		t_dll_add_front(head, nn);
	return (1);
}
