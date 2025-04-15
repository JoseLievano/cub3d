/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:03 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/11 15:32:55 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include <stdbool.h>

/* Verifica que el contenido de un mapa cumpla con los requisitos basicos:
 * 	- Ignorar espacios en blanco
 * 	- Validacion de caracteres
 * 	- Validacion de la posicion inicial del jugador
 * 	- Errores
 */
static int	validate_maps(t_data *dt, char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map_lines[i] != NULL)
	{
		j = 0;
		while (map_lines[i][j] != '\0')
		{
			while (ft_isspace(map_lines[i][j]))
				j++;
			if (!ft_strchr("10NSEW", map_lines[i][j]))
				return (error_msg(dt->mapinfo.path, ERR_INV_CHAR, FAILURE));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/* La funcion verifica que despues del final del mapa en el archivo .cub:
 * 1. No haya contenido no permitido
 * 2. Solo existan espacios en blanco en el resto del archivo
 */
static int	map_ends_correct(t_map *map_info)
{
	int	i;
	int	j;

	i = map_info->index_end_of_map;
	while (map_info->file[i])
	{
		j = 0;
		while (map_info->file[i][j])
		{
			if (!ft_strchr(" \t\r\n\v\f", map_info->file[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_data *game_data, char **map_content)
{
	if (!game_data->map)
		return (error_msg(game_data->mapinfo.path, ERR_MAP_MISSING, FAILURE));
	if (check_sides(&game_data->mapinfo, map_content) == FAILURE)
		return (error_msg(game_data->mapinfo.path, ERR_MAP_NO_WALLS, FAILURE));
	if (game_data->mapinfo.height < 3)
		return (error_msg(game_data->mapinfo.path, ERR_MAP_TOO_SMALL, FAILURE));
	if (validate_maps(game_data, map_content) == FAILURE)
		return (FAILURE);
	if (map_ends_correct(&game_data->mapinfo) == FAILURE)
		return (error_msg(game_data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
