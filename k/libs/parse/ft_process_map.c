/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:13 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:45:13 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

t_map	*ft_process_map(t_dll *file_content)
{
	t_map		*map;
	t_textures	*textures;

	map = malloc(sizeof(t_map *));
	textures = ft_get_textures(file_content);
	if (!textures)
		ft_error_prc_map(map, file_content, "Textures not loaded\n");
	map->textures = textures;
	return (map);
}
