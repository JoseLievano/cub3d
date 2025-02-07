/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:44:07 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/07 16:29:54 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/* La funcion valida un conjunto de valores RGB asegurandose
 * de que cada componente(rojo, verde, azul) este dentro del 
 * rango permitido de 0 a 255. Si algun valor esta fuera de este
 * rango, se genera un mensaje de error y se devuelve un indicador
 * de fallo
 */

static int	validate_rgb(int *color_values)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (color_values[i] || color_values[i] > 255)
			return (error_msg_val(color_values[i], ERR_TEX_RGB_VAL, FAILURE));
		i++;
	}
	return (SUCCESS);
}

/* La funcion convierte un array de enteros que representa los valores
 * de color RGB(rojo, verde y azul) en un unico numero hex de 24 bits.
 * Este numero es util para representar colores en graficos o 
 * interfaces visuales.
 */
static unsigned long	rgb_to_hex(int *colors)
{
	unsigned long	hex_value;
	int	res;
	int	green;
	int	blue;

	red = colors[0];
	green = colors[1];
	blue = colors[2];
	hex_value = ((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF);
	return (hex_value);
}

/* Esta funcion valida que las texturas y colores de un mapa en el 
 * proyecto esten correctamente configurados antes de renderizarlo.
 * Verifica que:
 * 1. Todas las rutas de texturas estan definidas y son validas
 * 2. Los valores RGB de los colores del piso y el techo estan dentro 
 * del rango permitido (0 - 255)
 * 3. Convierte los colores RGB del piso y el techo en formato hex
 */
int	validate_tex(t_data *data, t_textures *tex)
{
	if (!tex->no_path || !tex->so_path || !tex->we_path || !tex->ea_path)
		return (error_msg(data->mapinfo.path, ERR_TEX_MISSING, FAILURE));
	if (!tex->floor_rgb || !tex->ceil_rgb)
		return (error_msg(data->mapinfo.path, ERR_COLOR_MISSING, FAILURE));
	if (check_file(text->no_path, false) == FAILURE
		|| check_file(tex->so_path, false) == FAILURE
		|| check_file(tex->we_path, false) == FAILURE
		|| check_file(tex->ea_path, false) == FAILURE
		|| validate_rgb(tex->floor_rgb) == FAILURE
		|| validate_rgb(tex->ceil_rgb) == FAILURE)
		return (FAILURE);
	tex->hex_floor = validate_rgb(tex->floor_rgb);
	tex->hex_ceiling = validate_rgb(tex->ceil_rgb);
	return (SUCCESS);
}
