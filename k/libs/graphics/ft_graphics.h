/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:34:38 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 02:34:39 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H
# include "../../includes/cub3d.h"

typedef struct s_mlx	t_mlx;

typedef struct s_texture
{
	t_img	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
}	t_texture;

typedef struct s_graphics
{
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	t_img		*frame;
}	t_graphics;

typedef struct s_wall_slice
{
	int			x;
	t_ray		*ray;
	t_texture	*tex;
	int			line_height;
	int			draw_start;
}	t_wall_slice;

void		ft_graphics(t_game *game);
t_graphics	*ft_graphics_init(t_map *map, t_mlx *mlx);
void		ft_clear_frame(t_graphics *gfx);
void		ft_put_pixel(int x, int y, unsigned int px, t_img *img);
void		ft_draw_walls(t_game *game);
#endif
