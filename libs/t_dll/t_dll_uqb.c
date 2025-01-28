/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_uqb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:01:58 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/15 12:01:59 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

int	t_dll_uqb(t_dll **head, t_dll *nn, int (*cmp)(t_dll *, t_dll *))
{
	t_dll	*first_element;
	int		result;

	result = 10000;
	first_element = t_dll_get_head(*head);
	result = t_dll_contains(first_element, nn, cmp);
	if (result >= 0)
		result = 0;
	else
	{
		t_dll_add_back(head, nn);
		result = 1;
	}
	return (result);
}
