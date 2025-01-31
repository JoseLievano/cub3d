#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H
# include "../../includes/cub3d.h"

// MiniLibX context + textures
typedef struct s_mlx {
	void    *mlx_ptr;    // MiniLibX instance
	void    *win_ptr;    // Window pointer
	int     win_w;       // Window width
	int     win_h;       // Window height
} t_mlx;

// Loaded texture data
typedef struct s_texture {
	void    *img_ptr;    // MiniLibX image pointer
	char    *addr;       // Texture pixel data
	int     width;       // Texture width
	int     height;      // Texture height
	int     bpp;         // Bits per pixel
	int     line_len;    // Line length in bytes
} t_texture;

// All textures and frame buffer
typedef struct s_graphics {
	t_mlx       mlx;     // MiniLibX context
	t_texture   no_tex;  // North wall texture
	t_texture   so_tex;  // South wall texture
	t_texture   we_tex;  // West wall texture
	t_texture   ea_tex;  // East wall texture
	void        *frame;  // Current frame buffer
} s_graphics;

void	ft_graphics(void);
#endif