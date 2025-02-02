#ifndef FT_GAME_H
# define FT_GAME_H
# include "../../includes/cub3d.h"

typedef struct s_camera t_camera;
typedef struct s_ray t_ray;
typedef struct s_input t_input;
typedef struct s_map t_map;

// MiniLibX context + textures
typedef struct s_mlx {
	void    *mlx_ptr;    // MiniLibX instance
	void    *win_ptr;    // Window pointer
	int     win_w;       // Window width
	int     win_h;       // Window height
} t_mlx;

//Player data
typedef struct s_player {
	double  pos_x;     // Current X position
	double  pos_y;     // Current Y position
	double  dir_x;     // Direction vector
	double  dir_y;
	double  plane_x;   // Camera plane vector
	double  plane_y;
} t_player;

// Central struct passed between libraries
typedef struct s_game {
	t_mlx       *mlx;       // MiniLibX context
	t_player	*player;	//Player data
	t_input     *input;     // Current input state
	t_map       *map;       // Parsed map data
	t_camera    *camera;    // Camera plane (FOV)
	t_ray       *rays;     // Array of rays (one per screen column)
	bool        is_running; // Game loop flag
} t_game;

void ft_game(void);
#endif