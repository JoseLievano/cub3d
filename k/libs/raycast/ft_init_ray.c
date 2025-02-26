/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:25:33 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 04:25:34 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

static double	compute_delta(double dir)
{
	if (dir == 0)
		return (1e30);
	return (fabs(1 / dir));
}

static void	init_ray_x_step(t_game *game, t_ray *ray, double delta)
{
	double	pos;

	pos = game->player->pos_x;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos - ray->map_x) * delta;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((ray->map_x + 1.0) - pos) * delta;
	}
}

static void	init_ray_y_step(t_game *game, t_ray *ray, double delta)
{
	double	pos;

	pos = game->player->pos_y;
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos - ray->map_y) * delta;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((ray->map_y + 1.0) - pos) * delta;
	}
}

void	ft_init_ray(t_game *game, int x, t_ray *ray)
{
	double	camera_x;
	double	delta_x;
	double	delta_y;
	double	pos_x;
	double	pos_y;

	camera_x = 2 * x / (double)game->mlx->win_w - 1;
	ray->dir_x = game->player->dir_x
		+ game->player->plane_x * camera_x;
	ray->dir_y = game->player->dir_y
		+ game->player->plane_y * camera_x;
	pos_x = game->player->pos_x;
	pos_y = game->player->pos_y;
	ray->map_x = (int)pos_x;
	ray->map_y = (int)pos_y;
	delta_x = compute_delta(ray->dir_x);
	delta_y = compute_delta(ray->dir_y);
	init_ray_x_step(game, ray, delta_x);
	init_ray_y_step(game, ray, delta_y);
}
