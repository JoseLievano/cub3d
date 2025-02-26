/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:45:10 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 03:45:11 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCAST_H
# define FT_RAYCAST_H
# include "../../includes/cub3d.h"

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	bool	hit_side;
	double	wall_dist;
}	t_ray;

void	ft_raycast(t_game *game);
void	ft_perform_dda(t_game *game, t_ray *ray);
void	ft_init_ray(t_game *game, int x, t_ray *ray);
#endif
