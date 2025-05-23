/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:58:17 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 01:58:18 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

static int	close_x(t_game *game)
{
	ft_game_over(game);
	return (0);
}

void	ft_game(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = NULL;
	map = ft_parse(argc, argv);
	if (!map)
		exit(1);
	game = ft_game_init(map);
	mlx_do_key_autorepeatoff(game->mlx->mlx_ptr);
	mlx_hook(game->mlx->win_ptr,
		2, 1L << 0, ft_press_key, game);
	mlx_hook(game->mlx->win_ptr,
		3, 1L << 1, ft_release_key, game);
	mlx_hook(game->mlx->win_ptr, 17, 0, close_x, game);
	mlx_loop_hook(game->mlx->mlx_ptr, ft_game_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	ft_clean_game(game);
}
