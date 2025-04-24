/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:30:27 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:44:43 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

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

void	ft_local_clean_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
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
