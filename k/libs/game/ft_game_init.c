/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:18:14 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/20 11:18:15 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

static t_mlx	*ft_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->win_w = MAX_W;
	mlx->win_h = MAX_H;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			mlx->win_w, mlx->win_h, "Cube3D");
	if (!mlx->win_ptr)
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

static t_player	*ft_player_init(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = (double)map->spawn_x + 0.5;
	player->pos_y = (double)map->spawn_y + 0.5;
	set_player_dir_plane(player, map);
	return (player);
}

static t_ray	*ft_rays_init(t_game *game)
{
	t_ray	*rays;
	int		i;

	if (!game || !game->mlx)
		return (NULL);
	rays = (t_ray *)malloc(sizeof(t_ray) * game->mlx->win_w);
	if (!rays)
		return (NULL);
	i = 0;
	while (i < game->mlx->win_w)
	{
		rays[i].dir_x = 0;
		rays[i].dir_y = 0;
		rays[i].map_x = 0;
		rays[i].map_y = 0;
		rays[i].side_dist_x = 0;
		rays[i].side_dist_y = 0;
		rays[i].step_x = 0;
		rays[i].step_y = 0;
		rays[i].hit_side = false;
		rays[i].wall_dist = 0;
		i++;
	}
	return (rays);
}

t_game	*ft_game_init(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_clean_game(game));
	game->mlx = ft_mlx_init();
	if (!game->mlx)
		return (ft_clean_game(game));
	game->input = ft_input_init();
	if (!game->input)
		return (ft_clean_game(game));
	game->map = map;
	if (!game->map)
		return (ft_clean_game(game));
	game->player = ft_player_init(game->map);
	if (!game->player)
		return (ft_clean_game(game));
	game->gfx = ft_graphics_init(game->map, game->mlx);
	if (!game->gfx)
		return (ft_clean_game(game));
	game->rays = ft_rays_init(game);
	if (!game->rays)
		return (ft_clean_game(game));
	game->is_running = true;
	return (game);
}
