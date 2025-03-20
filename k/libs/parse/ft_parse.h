/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:06 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/20 16:30:31 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include <errno.h>
# include <stdbool.h>
# include <stddef.h>
//#include "/home/vanesa/42/cub3Dmio/cub3dcasi/k/libs/game/ft_game.h"
# include "../../includes/cub3d.h"

/*   MACROS   */

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
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_NO_WALLS "Map is not surronded by walls"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_TEXT_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing text"
# define ERR_COLOR_MISSING "Missing colors"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_FLOOR_CEILING "Invalid ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_TEXT_INVALID "Invalid texture"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"

enum e_output
{
	FAILURE = 1,
	SUCCESS = 0,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

// For storing parsed textures and colors
typedef struct s_textures
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_rgb;
	int				ceil_rgb;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textures;

// For storing map data and player spawn
typedef struct s_map
{
	char		*path;
	char		**file;
	int			line_count;
	char		**grid;
	int			rows;
	int			cols;
	int			index_end_of_map;
	int			height;
	int			width;
	int			is_valid;
	int			fd;
	t_textures	*textures;
	int			spawn_x;
	int			spawn_y;
	char		spawn_dir;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_map		mapinfo;
	char		**map;
	int			**textures;
	int			**textures_pixels;
	t_textures	texinfo;
}	t_data;

typedef struct s_minimap
{
	char	**map;
}	t_minimap;

//errors.c
int		error_msg(const char *context, char *msg, int exit_code);
int		error_msg_val(int context, char *msg, int exit_code);
//parse_args.c
int		check_file(const char *args, bool cub);
//ft_parse_utils.c
size_t	get_max_line_len(t_map *map, int i);
int		is_whitespace(char c);
//map_parser.c
int		validate_map(t_data *game_data, char **map_content);
//map_borders.c
int		check_sides(t_map *map, char **map_lines);
//create_map.c
int		built_map(t_data *game_data, char **file, int i);
//fill_color_text.c
int		parse_color_text(t_data *dt, t_textures *text, char *line, int i);
//map_loader.c
int		parse_map_file(t_data *game_data, char **map);
//ft_parse_data.c
void	parse_data(char *path, t_data *dt);
//free_data.c
void	free_tab(void **array);
int		free_data(t_data *data);
//check_text.c
int		validate_tex(t_data *data, t_textures *tex);
//init_textures.c
void    init_textures(t_textures *text);
//init_map.c
void    init_map(t_map *map);

#endif
