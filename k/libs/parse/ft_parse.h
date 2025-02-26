/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:06 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/26 11:14:48 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../../includes/cub3d.h"


/*   MACROS   */

# define WIN_HEIGHT 480
# define WIN_WIDTH 640

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define RESET "\e[0m"
# define RED "\e[31m"

// ERROR MESSAGES
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not a .xpm file"
# define ERR_INV_CHAR "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_NO_WALLS "Map is not surronded by walls"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_TEXT_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_FLOOR_CEILING "Invalid ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_TEXT_INVALID "Invalid texture"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"

enum e_output
{
	FAILURE = 1;
	SUCCESS = 0;
	ERR = 2;
	BREAK = 3;
	CONTINUE = 4;
}

typedef struct	s_image
{
	void	*img;
	int	*addr;
	int	pixel_bits;
	int	size_line;
	int	endian;
}	t_image;

// For storing parsed textures and colors
typedef struct s_textures
{
	char	*no_path;   // North texture path
	char	*so_path;   // South texture path
	char	*we_path;   // West texture path
	char	*ea_path;   // East texture path
	int		floor_rgb;  // Packed RGB (0xRRGGBB)
	int		ceil_rgb;   // Packed RGB (0xRRGGBB)
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int	size;
	double	step;
	double	pos;
	int	x;
	int	y;
} t_textures;

// For storing map data and player spawn
typedef struct s_map
{

	//Datos generales del archivo
	char	*path; //Ruta del archivo .cub
	char	**file; //Contenido del archivo .cub linea por linea
	int	line_count; //Numero total de lineas en el archivo	
	
	//Informacion del mapa
	char		**grid;      // 2D map grid (from .cub)
	int			rows;        // Map row count
	int			cols;        // Map column count
	int		index_end_of_map; //indica el final del mapa
	
	int	height;
	int	width;
	//Validacion del archivo
	int	is_valid; //Flag que indica si el archivo esta
			  //correctamente configurado
	int	fd;

	//Tecturas y colores
	t_textures	textures;  // Texture paths and colors
} t_map;

typedef struct s_player
{
	double	pos_x; //Posocion actual del jugador en el mapa
	double	pos_y; //Posicion actual del jugador en el mapa
	char 	dir;
	double	spawn_x; //Player starting X position
	double	spawn_y; //Player starting Y position
	char	spawn_dir; //Initial direction (N/S/E/W)
}	t_player;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int	win_height;
	int	win_width;
	t_player	player;
	t_map	mapinfo;
	char	**map;
	int	**textures;
	int	**textures_pixels;
	t_textures	texinfo;
}

typedef struct s_minimap
{
	char	**map;
}

//parse_args.c
int	check_file(const char *args, bool cub);
//ft_parse_utils.c
size_t	get_max_line_len(t_map *map, int i);
int	is_whitespace(char c);
//map_parser.c
int	validate_map(t_data *game_data, char **map_content);
//map_borders.c
int	check_sides(t_map *map, char **map_lines);
//create_map.c
int	built_map(t_data *game_data, char **file, int i);
//fill_color_text.c
int	parse_color_text(t_data *game_data, t_textures *text, char *line, int i);
//map_loader.c
int	parse_map_file(t_data *game_data, char **map);
//ft_parse_data.c
void	parse_data(char *path, t_data *data);
//free_data.c
void	free_tab(void **array);
int	free_data(t_data *data);


void	ft_parse_test(int argc, char **argv);
#endif
