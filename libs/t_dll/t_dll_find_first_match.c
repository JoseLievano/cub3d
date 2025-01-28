/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_find_first_match.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:14:01 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/19 18:14:02 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_first_mtch(t_dll *l, void **ar, int n, int (*c)(void **a, int n))
{
	t_dll	*found;
	t_dll	*head;

	found = NULL;
	head = t_dll_get_head(l);
	while (head)
	{
		ar[0] = head;
		if (c(ar, n) > 0)
		{
			found = head;
			break ;
		}
		head = head->next;
	}
	return (found);
}
