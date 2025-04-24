/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:17:15 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/23 18:17:16 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

static void	rotate_vector(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle)
		- *y * sin(angle);
	*y = old_x * sin(angle)
		+ *y * cos(angle);
}

static void	rotate_player(double angle_speed, t_player *player, t_input *input)
{
	if (input->r_r)
	{
		rotate_vector(&player->dir_x, &player->dir_y, angle_speed);
		rotate_vector(&player->plane_x, &player->plane_y, angle_speed);
	}
	if (input->r_l)
	{
		rotate_vector(&player->dir_x, &player->dir_y, -angle_speed);
		rotate_vector(&player->plane_x, &player->plane_y, -angle_speed);
	}
}

void	ft_move_player(t_game *game)
{
	t_player	*player;
	t_input		*input;
	double		angle_speed;
	double		speed;

	player = game->player;
	input = game->input;
	angle_speed = 0.04;
	speed = 0.06;
	rotate_player(angle_speed, player, input);
	ft_walk(speed, player, input, game);
}
