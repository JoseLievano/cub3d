/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:49 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/06 18:45:27 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	top_bottom_check(char **map_lines, int i, int j)
{
	if (!map_lines || !map_lines[i] || !map_lines[i][j])
		return (FAILURE);
	while (map_lines[i][j] == ' ' || map_lines[i][j] == '\t'
	|| map_lines[i][j] == '\r' || map_lines[i][j] == '\v'
	|| map_lines[i][j] == '\f')
		j++;
	while (map_lines[i][j])
	{
		if (map_lines[i][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_sides(t_map *map, char **map_lines)
{
	int	i;
	int	j;

	if (top_botton_check(map_lines, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_lines[i]) - 1;
		if (map_lines[i][j] != '1')
			return (FAILURE);
		i++;
	}
	if (top_botton_check(map_lines, i, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
