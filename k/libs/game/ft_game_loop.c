/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:01:53 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/23 22:01:54 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

int	ft_game_loop(t_game *game)
{
	ft_move_player(game);
	ft_raycast(game);
	ft_graphics(game);
	return (0);
}
