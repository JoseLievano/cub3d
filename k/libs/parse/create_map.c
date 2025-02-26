/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:28:30 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/14 15:57:48 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/* La funcion se encarga de contar la cantidad de  lineas consecutivas 
 * en el archivo que forman parte de la seccion del mapa. Esto incluye
 * saltar espacios en blanco al principio de cada linea y validar que 
 * cada linea comienza con un caracter '1', que indica el inicio valido
 * de una linea del mapa.
 */
static int	count_lines_map(t_data *game_data, char **file, int i)
{
	int	start;
	int	j;
	
	start = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	game_data->mapinfo.index_end_of_map = i;
	return (i - start);
}

/* Esta funcion copia las lineas de texto del archivo (mapinfo->file) que 
 * representan el mapa, comenzando desde un indice especifico (start_index),
 * a un nuevo arreglo de cadenas (map_tab). Se asegura de que todas las
 * lineas tengan la misma longitud (rellenando con '\0' si es necesario)
 */
static int	fill_map_tab(t_map *map_info, char **map_tab, int start)
{
	int	i;
	int	j;

	map_info->width = get_max_line_len(map_info, start);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map_tab[i])
			return (error_msg(NULL, ERR_MALLOC, FAILURE));
		while (map_info->file[start][j] && map_info[start][j] != '\n')
		{
			map_tab[i][j] = map_info[start][j];
			j++;
		}
		while (j < map_info->width)
			map_tab[i][j++] = '\0';
		i++;
		start++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

/* La funcion se encarga de extraer y almacenar la info del mapa
 * (las lineas de texto que representan el dise;o del mapa) en una
 * estructura de datos interna (data->map). Esto incluye contar las
 * lineas relevantes del mapa, asignar memoria para almacenarlas y 
 * copiar el contenido del archivo al nuevo arreglo de cadenas.
 */
static int	parse_map_info(t_data *game_data, char **file, int i)
{
	game_data->mapinfo.height = count_lines_map(data, file, i);
	game_data->map = malloc(sizeof(char *) * (game_data->mapinfo.height + 1));
	if (!game_data->map)
		return (error_msg(NULL, ERR_MALLOC, FAILURE));
	if (fill_map_tab(&game_data->mapinfo, game_data->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/* Esta funcion modifica la representacion interna del mapa (data->map)
 * reemplazando espacios dentro de cada fila por paredes('1'), excepto
 * aquellos espacios que se encuentran al final de una fila. Esto asegura
 * que el mapa tenga una estructura mas robusta para evitar errores en la 
 * validacion o renderizacion.
 */
static void replace_spaces_with_walls(t_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j] == ' ' || game_data->map[i][j] == '\t'
			|| game_data[i][j] == '\r' || game_data->map[i][j] == '\v'
			|| game_data[i][j] == '\f')
			j++;
		while (game_data->map[i][j++])
		{
			if (game_data->map[i][j] == ' '
				&& j != game_data->map[i][ft_strlen(game_data->map[i]) - 1])
				game_data->map[i][j] = '1';
		}
		i++;
	}
}
/* Esta funcion se encarga de inicializar la info del mapa y realizar las 
 * transformaciones necesarias para asegurar que cumpla con los requisitos
 * de dise;o:
 * 1. Obtener y asignar info basica del mapa
 * 2. Transformar espacios dentro del mapa en paredes('1')
 */
int	built_map(t_data *game_data, char **file, int i)
{
	if (parse_map_info(game_data, file, i) == FAILURE)
		return (FAILURE);
	replace_spaces_with_walls(game_data);
	return (SUCCESS);
}
