/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:36:03 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/23 13:36:04 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == 120 || keycode == 65307)
		ft_game_over(game);
	else if (keycode == 122 || keycode == 65362 || keycode == 107)
		game->input->up = true;
	else if (keycode == 100 || keycode == 108)
		game->input->right = true;
	else if (keycode == 115 || keycode == 65364 || keycode == 106)
		game->input->down = true;
	else if (keycode == 113 || keycode == 104)
		game->input->left = true;
	else if (keycode == 65363)
		game->input->r_r = true;
	else if (keycode == 65361)
		game->input->r_l = true;
	return (0);
}

int	ft_release_key(int keycode, t_game *game)
{
	(void) game;
	if (keycode == 122 || keycode == 65362 || keycode == 107)
		game->input->up = false;
	else if (keycode == 100 || keycode == 108)
		game->input->right = false;
	else if (keycode == 115 || keycode == 65364 || keycode == 106)
		game->input->down = false;
	else if (keycode == 113 || keycode == 104)
		game->input->left = false;
	else if (keycode == 65363)
		game->input->r_r = false;
	else if (keycode == 65361)
		game->input->r_l = false;
	return (0);
}
