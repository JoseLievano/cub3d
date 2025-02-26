/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:45:28 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 03:45:29 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

static double	calculate_perp_distance(t_ray *ray)
{
	double	perp_distance;
	double	delta;

	if (!ray->hit_side)
	{
		if (ray->dir_x == 0)
			delta = 1e30;
		else
			delta = fabs(1 / ray->dir_x);
		perp_distance = ray->side_dist_x - delta;
	}
	else
	{
		if (ray->dir_y == 0)
			delta = 1e30;
		else
			delta = fabs(1 / ray->dir_y);
		perp_distance = ray->side_dist_y - delta;
	}
	return (perp_distance);
}

void	ft_raycast(t_game *game)
{
	int		x;
	t_ray	*ray;

	x = 0;
	while (x < game->mlx->win_w)
	{
		ray = &game->rays[x];
		ft_init_ray(game, x, ray);
		ft_perform_dda(game, ray);
		ray->wall_dist = calculate_perp_distance(ray);
		x++;
	}
}
