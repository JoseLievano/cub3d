/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:17:30 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/21 03:17:31 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	clean_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->no_path)
		free(textures->no_path);
	if (textures->so_path)
		free(textures->so_path);
	if (textures->we_path)
		free(textures->we_path);
	if (textures->ea_path)
		free(textures->ea_path);
	free(textures);
}

void	ft_clean_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->textures)
		clean_textures(map->textures);
	free(map);
}
