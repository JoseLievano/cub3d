/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:15 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/20 15:43:28 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void    init_textures(t_textures *text)
{
    if (!text)
    {
	printf("ERROR: El puntero a texturas es nulo\n");
        return ;
    }
    printf("Iniciallizacion texturas...\n");

    text->no_path = ft_strdup("textures/wall_1.xpm");
    text->so_path = ft_strdup("textures/wall_2.xpm");
    text->we_path = ft_strdup("textures/wood.xpm");
    text->ea_path = ft_strdup("textures/wood.xpm");
    text->floor_rgb = -1;
    text->ceil_rgb = -1;
    text->hex_ceiling = 0;
    text->hex_floor = 0;
    printf("Texturas inicializadas correctamente\n");
}
