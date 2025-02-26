/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:55:20 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 02:55:22 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

static void	ft_draw_row(t_game *game, int y, unsigned int ceil_color,
		unsigned int floor_color)
{
	int	x;

	x = 0;
	while (x < MAX_W)
	{
		if (y < MAX_H / 2)
			ft_put_pixel(x, y, ceil_color, game->gfx->frame);
		else
			ft_put_pixel(x, y, floor_color, game->gfx->frame);
		x++;
	}
}

void	ft_draw_floor_and_ceiling(t_game *game)
{
	unsigned int	ceil_color;
	unsigned int	floor_color;
	int				y;

	ceil_color = game->map->textures->ceil_rgb;
	floor_color = game->map->textures->floor_rgb;
	y = 0;
	while (y < MAX_H)
	{
		ft_draw_row(game, y, ceil_color, floor_color);
		y++;
	}
}

void	ft_graphics(t_game *game)
{
	ft_clear_frame(game->gfx);
	ft_draw_floor_and_ceiling(game);
	ft_draw_walls(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr,
		game->mlx->win_ptr, game->gfx->frame, 0, 0);
}
