#ifndef FT_RAYCAST_H
# define FT_RAYCAST_H
# include "../../includes/cub3d.h"


// Represents a single ray
typedef struct s_ray {
	double  dir_x;       // Ray direction (X)
	double  dir_y;       // Ray direction (Y)
	int     map_x;       // Current map grid X
	int     map_y;       // Current map grid Y
	double  side_dist_x; // Distance to next X-side
	double  side_dist_y; // Distance to next Y-side
	int     step_x;      // X step direction (-1 or 1)
	int     step_y;      // Y step direction (-1 or 1)
	bool    hit_side;    // Wall side (NS/EW)
	double  wall_dist;   // Perpendicular wall distance
} t_ray;

// Camera/player view data
typedef struct s_camera {
	double  plane_x;     // Camera plane X (FOV)
	double  plane_y;     // Camera plane Y (FOV)
} t_camera;

void	ft_raycast(void);
#endif