/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:10:19 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/17 15:11:08 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

void	t_dll_clear(t_dll *node, void (*n_clear)(t_dll*))
{
	t_dll	*head;
	t_dll	*temp;
	size_t	lst_size;

	head = t_dll_get_head(node);
	lst_size = t_dll_size(head);
	if (lst_size == 0)
		return ;
	if (lst_size == 1)
	{
		n_clear(head);
		free(node);
		return ;
	}
	if (lst_size > 1)
	{
		while (head)
		{
			temp = head;
			n_clear(head);
			head = head->next;
			free(temp);
		}
	}
}
