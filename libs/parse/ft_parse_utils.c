/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:26:06 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/04 14:49:56 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

/*Verifica si un caracter es un caracter de un espacio en blanco
' '(espacio)
'\t'(tabulacion horizontal)
'\r'(retorno de carro)
'\n'(nueva linea)
'\v'(tabulacion vertical)
'\f'(salto de pagina)
*/
int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f')
		return (SUCCES);
	else
		return (FAILURE);
}
/*Encuentra la longitud de la linea mas larga en el archivo .cub
 * o en un conjunto de cadenas representadas en map->file
 * - Determinar el tamanyo max necesario para procesar o almacenar
 *   las lineas del mapa
 * - Garantizar un manejo consistente del mapa
 * - Ayuda al renderizado de la vista 3D
 */
size_t	get_max_line_len(t_map *map, int i)
{
	size_t	max_len;
	size_t	cur_len;

	max_len = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		cur_len = ft_strlen(map->file[i]);
		if (cur_len > max_len)
			max_len = cur_len;
		i++;
	}
	return (max_len);
}
