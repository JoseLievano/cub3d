/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:41:44 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 02:41:45 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

static void	draw_wall_pixels(t_game *game, t_wall_slice *ws, int tex_x,
	double tex_pos)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;

	step = (double)ws->tex->height / ws->line_height;
	y = ws->draw_start;
	while (y < ws->draw_start + ws->line_height && y < game->mlx->win_h)
	{
		tex_y = (int)tex_pos & (ws->tex->height - 1);
		tex_pos += step;
		color = *((int *)(ws->tex->addr + (tex_y * ws->tex->line_len)
					+ (tex_x * (ws->tex->bpp / 8))));
		ft_put_pixel(ws->x, y, color, game->gfx->frame);
		y++;
	}
}

void	ft_draw_wall_slice(t_game *game, t_wall_slice *ws)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

	if (!ws->ray->hit_side)
		wall_x = game->player->pos_y + ws->ray->wall_dist * ws->ray->dir_y;
	else
		wall_x = game->player->pos_x + ws->ray->wall_dist * ws->ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)ws->tex->width);
	if ((!ws->ray->hit_side && ws->ray->dir_x > 0) || (ws->ray->hit_side
			&& ws->ray->dir_y < 0))
		tex_x = ws->tex->width - tex_x - 1;
	step = (double)ws->tex->height / ws->line_height;
	tex_pos = (ws->draw_start - game->mlx->win_h / 2 + ws->line_height / 2)
		* step;
	draw_wall_pixels(game, ws, tex_x, tex_pos);
}

static t_texture	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_side)
	{
		if (ray->dir_y < 0)
			return (&game->gfx->no_tex);
		return (&game->gfx->so_tex);
	}
	if (ray->dir_x < 0)
		return (&game->gfx->we_tex);
	return (&game->gfx->ea_tex);
}

static void	set_wall_slice(t_game *game, int x, t_wall_slice *ws)
{
	t_ray	*ray;
	int		line_height;
	int		draw_start;

	ray = &game->rays[x];
	line_height = (int)(game->mlx->win_h / ray->wall_dist);
	draw_start = -line_height / 2 + game->mlx->win_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	ws->x = x;
	ws->ray = ray;
	ws->line_height = line_height;
	ws->draw_start = draw_start;
	ws->tex = select_texture(game, ray);
}

void	ft_draw_walls(t_game *game)
{
	int				x;
	t_wall_slice	ws;

	x = 0;
	while (x < game->mlx->win_w)
	{
		set_wall_slice(game, x, &ws);
		ft_draw_wall_slice(game, &ws);
		x++;
	}
}
