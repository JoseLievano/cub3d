/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:53:51 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/25 14:53:52 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

bool	is_walkable(t_game *game, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)x;
	grid_y = (int)y;
	if (game->map->grid[grid_y][grid_x] != '1')
		return (true);
	return (false);
}

static void	ft_v(double speed, t_player *player, t_input *input, t_game *game)
{
	double	new_x;
	double	new_y;

	if (input->up)
	{
		new_x = player->pos_x + player->dir_x * speed;
		new_y = player->pos_y + player->dir_y * speed;
		if (is_walkable(game, new_x, player->pos_y))
			player->pos_x = new_x;
		if (is_walkable(game, player->pos_x, new_y))
			player->pos_y = new_y;
	}
	if (input->down)
	{
		new_x = player->pos_x - player->dir_x * speed;
		new_y = player->pos_y - player->dir_y * speed;
		if (is_walkable(game, new_x, player->pos_y))
			player->pos_x = new_x;
		if (is_walkable(game, player->pos_x, new_y))
			player->pos_y = new_y;
	}
}

static void	ft_h(double speed, t_player *player, t_input *input, t_game *game)
{
	double	new_x;
	double	new_y;

	if (input->right)
	{
		new_x = player->pos_x + player->plane_x * speed;
		new_y = player->pos_y + player->plane_y * speed;
		if (is_walkable(game, new_x, player->pos_y))
			player->pos_x = new_x;
		if (is_walkable(game, player->pos_x, new_y))
			player->pos_y = new_y;
	}
	if (input->left)
	{
		new_x = player->pos_x - player->plane_x * speed;
		new_y = player->pos_y - player->plane_y * speed;
		if (is_walkable(game, new_x, player->pos_y))
			player->pos_x = new_x;
		if (is_walkable(game, player->pos_x, new_y))
			player->pos_y = new_y;
	}
}

void	ft_walk(double speed, t_player *player, t_input *input, t_game *game)
{
	ft_v(speed, player, input, game);
	ft_h(speed, player, input, game);
}
