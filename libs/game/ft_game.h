#ifndef FT_GAME_H
# define FT_GAME_H
# include "../../includes/cub3d.h"

// Central struct passed between libraries
typedef struct s_game {
	t_mlx       mlx;       // MiniLibX context
	t_input     input;     // Current input state
	t_map       map;       // Parsed map data
	t_textures  textures;  // Texture paths and colors
	t_camera    camera;    // Camera plane (FOV)
	t_ray       *rays;     // Array of rays (one per screen column)
	double      pos_x;     // Player X position
	double      pos_y;     // Player Y position
	double      dir_x;     // Player direction X
	double      dir_y;     // Player direction Y
	bool        is_running; // Game loop flag
} t_game;

void ft_game(void);
#endif