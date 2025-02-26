/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:09:31 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/19 18:09:33 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

static void	load_texture(void *mlx_ptr, t_texture *tex, char *path)
{
	int		width;
	int		height;
	int		endian;

	tex->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	if (tex->img_ptr)
	{
		tex->width = width;
		tex->height = height;
		tex->addr = mlx_get_data_addr(tex->img_ptr,
				&tex->bpp, &tex->line_len, &endian);
	}
	else
	{
		tex->width = 0;
		tex->height = 0;
		tex->addr = NULL;
		tex->bpp = 0;
		tex->line_len = 0;
	}
}

t_graphics	*ft_graphics_init(t_map *map, t_mlx *mlx)
{
	t_graphics	*gfx;
	void		*mlx_ptr;

	if (!map || !map->textures)
		return (NULL);
	gfx = (t_graphics *)malloc(sizeof(t_graphics));
	if (!gfx)
		return (NULL);
	mlx_ptr = mlx->mlx_ptr;
	if (!mlx_ptr)
	{
		free(gfx);
		return (NULL);
	}
	load_texture(mlx_ptr, &gfx->no_tex, map->textures->no_path);
	load_texture(mlx_ptr, &gfx->so_tex, map->textures->so_path);
	load_texture(mlx_ptr, &gfx->we_tex, map->textures->we_path);
	load_texture(mlx_ptr, &gfx->ea_tex, map->textures->ea_path);
	gfx->frame = mlx_new_image(mlx_ptr, MAX_W, MAX_H);
	return (gfx);
}
