/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:00:10 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 02:02:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H
# include "../../includes/cub3d.h"

typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_input		t_input;
typedef struct s_textures	t_textures;
typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_graphics	t_graphics;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_w;
	int		win_h;
}	t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	t_mlx		*mlx;
	t_player	*player;
	t_input		*input;
	t_map		*map;
	t_ray		*rays;
	t_graphics	*gfx;
	bool		is_running;
}	t_game;

void	ft_game(void);
t_game	*ft_game_init(t_map *map);
void	ft_game_over(t_game *game);
int		ft_press_key(int keycode, t_game *game);
int		ft_release_key(int keycode, t_game *game);
int		ft_game_loop(t_game *game);
void	ft_move_player(t_game *game);
void	ft_walk(double speed, t_player *player, t_input *input, t_game *game);
void	set_player_dir_plane(t_player *player, t_map *map);
#endif
