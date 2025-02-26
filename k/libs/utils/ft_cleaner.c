/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:39:26 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/20 14:39:27 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	ft_clean_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}

static void	ft_clean_graphics(t_game *game)
{
	if (!game->gfx)
		return ;
	if (game->mlx && game->mlx->mlx_ptr)
	{
		if (game->gfx->frame)
			mlx_destroy_image(game->mlx->mlx_ptr, game->gfx->frame);
		if (game->gfx->no_tex.img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->gfx->no_tex.img_ptr);
		if (game->gfx->so_tex.img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->gfx->so_tex.img_ptr);
		if (game->gfx->we_tex.img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->gfx->we_tex.img_ptr);
		if (game->gfx->ea_tex.img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->gfx->ea_tex.img_ptr);
	}
	free(game->gfx);
}

void	*ft_clean_game(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->input)
		free(game->input);
	if (game->map)
		ft_clean_map(game->map);
	if (game->rays)
		free(game->rays);
	if (game->gfx)
		ft_clean_graphics(game);
	if (game->mlx)
		ft_clean_mlx(game->mlx);
	free(game);
	return (NULL);
}
