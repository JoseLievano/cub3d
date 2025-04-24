/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zeros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:43:17 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:43:19 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static bool	is_valid_tile(char c)
{
	if (c == '0' || c == '1')
		return (true);
	return (false);
}

static bool	valid_horizontal(char *row, size_t x)
{
	size_t	len;

	len = ft_strlen(row);
	if (x == 0)
		return (false);
	if (!is_valid_tile(row[x - 1]))
		return (false);
	if (x + 1 >= len)
		return (false);
	if (!is_valid_tile(row[x + 1]))
		return (false);
	return (true);
}

static bool	valid_vertical(t_dll *node, size_t x)
{
	char	*row;
	size_t	len;

	if (!node->prev || !node->next)
		return (false);
	row = (char *)node->prev->content;
	len = ft_strlen(row);
	if (x >= len || !is_valid_tile(row[x]))
		return (false);
	row = (char *)node->next->content;
	len = ft_strlen(row);
	if (x >= len || !is_valid_tile(row[x]))
		return (false);
	return (true);
}

bool	ft_check_zeros(t_dll *grid)
{
	t_dll	*node;
	char	*row;
	size_t	x;

	node = t_dll_get_head(grid);
	while (node)
	{
		row = (char *)node->content;
		x = 0;
		while (row[x])
		{
			if (row[x] == '0')
			{
				if (!valid_horizontal(row, x) || !valid_vertical(node, x))
					return (false);
			}
			x++;
		}
		node = node->next;
	}
	return (true);
}
