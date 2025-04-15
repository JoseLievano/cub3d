/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:21:38 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/20 11:25:34 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include <stdio.h>
void    init_map(t_map *map)
{
    if (!map)
    {
	printf("Error: El mapa no se ha inicializado correctamente.\n");
        return ;
    }
    printf("Inicializando mapa...\n");
    map->path = NULL;
    map->file = NULL;
    map->line_count = 0;
    map->rows = 0;
    map->cols = 0;
    map->index_end_of_map = 0;
    map->height = 0;
    map->width = 0;
    map->is_valid = 0;
    map->fd = -1;
    map->textures = malloc(sizeof(t_textures));
    if (!map->textures)
    {
        error_msg("Memoria", "Fallo en la asignacion de texturas", FAILURE);
        return ;
    }
    printf("Texturas asignadas con exito.\n");
    init_textures(map->textures);
    if (!map->textures->no_path || !map->textures->so_path || !map->textures->we_path || !map->textures->ea_path)
    {
	    printf("Error en las rutas de las texturas.\n");
	    return ;
    }
    printf("Texturas inicializadas correctamente.\n");

    map->spawn_x = -1;
    map->spawn_y = -1;
    map->spawn_dir = '\0';

    printf("Mapa inicializado correctamente.\n");

}
