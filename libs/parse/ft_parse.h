/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:06 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/06 17:34:38 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../../includes/cub3d.h"


/*   MACROS   */

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

// ERROR MESSAGES
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not a .xpm file"
# define ERR_INV_CHAR "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)
# define ERR_PLAYER_POS "Invalid player position"

enum e_output
{
	FAILURE = 1;
	SUCCESS = 0;
}

// For storing parsed textures and colors
typedef struct s_textures
{
	char	*no_path;   // North texture path
	char	*so_path;   // South texture path
	char	*we_path;   // West texture path
	char	*ea_path;   // East texture path
	int		floor_rgb;  // Packed RGB (0xRRGGBB)
	int		ceil_rgb;   // Packed RGB (0xRRGGBB)
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
	//Validacion del archivo
	int	is_valid; //Flag que indica si el archivo esta
			  //correctamente configurado

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
	t_player	player;
	t_map	mapinfo;
	char	**map;
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

void	ft_parse(void);
void	ft_parse_test(int argc, char **argv);
#endif
