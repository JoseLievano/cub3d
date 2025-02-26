/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:46:40 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:09 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/*Extrae la ruta de un archivo desde una linea de texto (line),
 * a partir de una posicion especifica (i)
 * 1. Saltarse los espacios en blanco iniciales
 * 2. determinar la longitud del path
 * 3. Reservar memoria para el path
 * 4. Copiar el path en la nueva cadena
 * 5. Verificar que no haya caracteres sobrantes despues del path
 */
static char	*extract_text_path(char *line, int i)
{
	int	len;
	int	j;
	char	*path;

	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] && line[len] != ' ' && line[len] != '\t')
		len++;
	path = malloc(sizeof(char) * (len - i + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		path[j++] = line[i++];
	path[j] = '\0';
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != '\n')
	{
		free(path);
		return (NULL);
	}
	return (path);
}

/* Asigna las rutas de texturas direccionales (north, south, west, east) en la
 * estructura textures, a partir de una linea de configuracion (line)
 * 1. Verificacion de caracteres no validos
 * 2. Comparacion de los identificadores de direccion
 */
static int assign_text_path(t_textures *text, char *line, int i)
{
	if (line[i + 1] && ft_isprint(line[i + 2]))
		return (ERR);
	if (line[i] == 'N' && line[i + 1] == 'O' && !text->no_path)
		text->no_path = extract_text_path(line, i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O' && !text->so_path)
		text->so_path = extract_text_path(line, i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && !text->we_path)
		text->we_path = extract_text_path(line, i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A' && !text->ea_path)
		text->ea_path = extract_text_path(line, i + 2);
	else
		return (ERR);
	return (SUCCESS);
}

/*Analiza una linea del mapa y se encarga de identificar que tipo de info
 * contiene:
 * Texturas direccioneslaes(NO, SO, WE, EA)
 * Colores(F y C)
 * Datos del mapa(1 o 0)
 */
static int	skip_spaces_and_parse(t_data *game_data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1]) && !ft_isdigit(map[i][j]))
		{
			if (assign_text_path(&game_data->texinfo, map[i], j) == ERR)
				return (error_msg(game_data->mapinfo.path, ERR_TEXT_INVALID, FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_color_text(game_data, &game_data->texinfo, map[i], j) == ERR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (built_map(game_data, map, i) == FAILURE)
			return (error_msg(game_data->mapinfo.path, ERR_INVALID_MAP, FAILURE))
		return (SUCCESS)
	}
	return (CONTINUE);
}

/* Se encarga de analizar el contenido del mapa linea por linea y caracter por
 * caracter, identificando informacion relevante dentro del archivo del mapa
 * 1. Recorre el archivo linea por linea usando el indice i
 * 2. Dentro de cada linea, recorre cada caracter con el indice j
 * 3. Llama a skip_spaces_and_parse para procesar la info del mapa y determinar
 * como manejar cada linea.
 * Si el retorno es BREAK, interrumpe el bucle interno y pasa a la siguiente linea
 * Si devuelve FAILURE, la funcion termina con error
 * Si devuelve SUCCESS, la funcion finaliza correctamente
 * 4. Si no hay errores, la funcion retorna SUCCESS al final
 */
int	parse_map_file(t_data *game_data, char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			res = skip_spaces_and_parse(game_data, map, i, j);
			if (res == BREAK)
				break ;
			if (res == FAILURE)
				return (FAILURE);
			if (res == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
