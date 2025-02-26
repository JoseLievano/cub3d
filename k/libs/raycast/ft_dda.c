/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:06:43 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 04:06:45 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

static void	update_ray_x(t_ray *ray)
{
	double	delta;

	if (ray->dir_x == 0)
		delta = 1e30;
	else
		delta = fabs(1 / ray->dir_x);
	ray->side_dist_x += delta;
	ray->map_x += ray->step_x;
}

static void	update_ray_y(t_ray *ray)
{
	double	delta;

	if (ray->dir_y == 0)
		delta = 1e30;
	else
		delta = fabs(1 / ray->dir_y);
	ray->side_dist_y += delta;
	ray->map_y += ray->step_y;
}

void	ft_perform_dda(t_game *game, t_ray *ray)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			update_ray_x(ray);
			side = 0;
		}
		else
		{
			update_ray_y(ray);
			side = 1;
		}
		if (game->map->grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	if (side == 1)
		ray->hit_side = true;
	else
		ray->hit_side = false;
}
