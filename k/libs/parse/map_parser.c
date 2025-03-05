/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:03 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/03 17:01:19 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/* Verifica que el contenido de un mapa cumpla con los requisitos basicos:
 * 	- Ignorar espacios en blanco
 * 	- Validacion de caracteres
 * 	- Validacion de la posicion inicial del jugador
 * 	- Errores
 */
static int	validate_map(t_data *game_data, char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	//game_data->player.dir = '\0';
	while (map_lines[i] != NULL)
	{
		j = 0;
		while (map_lines[i][j] != '\0')
		{
			while (ft_isspace(map_lines[i][j]))
				j++;
			if (!ft_strchr("10NSEW", map_lines[i][j]))
				return (error_msg(game_data->mapinfo.path, ERR_INV_CHAR, FAILURE));
			/*if (ft_strchr("NSEW", map_lines[i][j]))
			{
				if (game_data->player.dir != '\0')
					return (error_msg(game_data->mapainfo.path, ERR_NUM_PLAYER, FAILURE));
				game_data->player.dir = map_lines[i][j];
			}*/
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/* Verifica si la posicion inicial del jugador es valida en el mapa.
 * El objetivo es asegurar que el jugador no este adyacente a un espacio
 * vario y que las posiciones vecinas sean seguras.
 *
static int	check_pos(t_data *game_data, char **map_grid)
{
	int	i;
	int	j;

	i = (int)game_data->player.pos_y;
	j = (int)game_data->player.pos_x;

	if ((ft_strlen(map_grid[i - 1]) <= (size_t)j) ||
	    (ft_strlen(map_grid[i + 1] <= (size_t)j) ||
	    (is_whitespace(map_grid[i][j - 1]) == SUCCESS) ||
	    (is_whitespace(map_grid[i][j + 1]) == SUCCESS) ||
	    (is_whitespace(map_grid[i - 1][j]) == SUCCESS) ||
	    (is_whitespace(map_grid[i + 1][j]) == SUCCESS))
	    	return (FAILURE);
	return (SUCCESS);
}

 * La funcion verifica que:
 * 1. El jugador tenga una direccion inicial configurada
 * 2. Encuentra la posicion inicial del jugador en el mapa
 * 3. Guarda esa posicion en la estructura player
 * 4. Sustituye la direccion en el mapa con un '0' para marcar la celda como transitable
 * 5. Llama a una funcion auxiliar para verificar si la posicion inicial es valida.
 *
static int	check_player_pos(t_data *game, char **map_grid)
{
	int	i;
	int	j;

	if (game->player.dir == '0')
		return (error_msg(game->mapinfo.path, ERR_PLAYER_DIR, FAILURE));
	i = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			if (ft_strchr("NSEW", map_grid[i][j]))
			{
				game->player.pos_x = (double)j + 0.5;
				game->player.pos_y = (double)i + 0.5;
				map_grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_pos(game, map_grid) == FAILURE)
		return (error_msg(game->mapinfo.path, ERR_PLAYER_POS, FAILURE));
	return (SUCCESS);
}*/

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
	if (validate_map(game_data, map_content) == FAILURE)
		return (FAILURE);
	if (check_player_pos(game_data, map_content) == FAILURE)
		return (FAILURE);
	if (map_ends_correct(&game_data->mapinfo) == FAILURE)
		return (error_msg(game_data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
