/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:52 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/11 15:50:01 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/* Verifica si una cadena esta compuesta unicamente por caracteres
 * que no son digitos
 */
static bool	only_no_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

/* La funcion convierte un arreglo de cadenas que representan valores
 * RGB en un arreglo de eneros. Ademas, valida los valores y libera
 * memoria en caso de errores.
 */
static int	*convert_rgb_array(char **rgb_to_convert, int *rgb)
{
	int	i;

	i = 0;
	while (rgb_to_convert[i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || only_no_digits(rgb_to_convert[i]))
		{
			free_tab((void **)rgb_to_convert);
			free(rgb);
			return (NULL);
		}
		i++;
	}
	free_tab((void **)rgb);
	return (rgb);
}

/* Toma una cadena que representa un color en formato RGB separado por
 * comas y la convierte en un arreglo de tres enteros representando los
 * valores rojo, verde y azul.
 */
static int	*parse_rgb_values(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		i;

	rgb_to_convert = ft_split(line, ',');
	i = 0;
	while (rgb_to_convert[i])
		i++;
	if (i != 3)
	{
		free_tab((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		error_msg(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (convert_rgb_array(rgb_to_convert, rgb));
}

/* Analiza una linea de entrada para determinar si debe establecer los 
 * colores del techo o del piso en la estructura t_textures. Se encarga
 * de convertir los valores RGB desde la linea y validar que sean correctos
 */
int	parse_color_text(t_data *dt, t_textures *text, char *line, int i)
{
	if (line[i + 1] && ft_isprint(line[i + 1]))
		return (error_msg(dt->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	if (!text->ceil_rgb && line[i] == 'C')
	{
		text->ceil_rgb = parse_rgb_values(line + i + 1);
		if (text->ceil_rgb == 0)
			return (error_msg(dt->mapinfo.path, ERR_COLOR_CEILING, ERR));
	}
	else if (!text->floor_rgb && line[i] == 'F')
	{
		text->floor_rgb = parse_rgb_values(line + i + 1);
		if (text->floor_rgb == 0)
			return (error_msg(dt->mapinfo.path, ERR_COLOR_FLOOR, ERR));
	}
	else
		return (error_msg(dt->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	return (SUCCESS);
}
