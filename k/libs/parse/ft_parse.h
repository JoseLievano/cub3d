#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../../includes/cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// For storing parsed textures and colors
typedef struct s_textures {
	char	*no_path;   // North texture path
	char	*so_path;   // South texture path
	char	*we_path;   // West texture path
	char	*ea_path;   // East texture path
	int		floor_rgb;  // Packed RGB (0xRRGGBB)
	int		ceil_rgb;   // Packed RGB (0xRRGGBB)
} t_textures;

// For storing map data and player spawn
typedef struct s_map {
	char		**grid;      // 2D map grid (from .cub)
	int			rows;        // Map row count
	int			cols;        // Map column count
	int			spawn_x;     // Player starting X position
	int			spawn_y;     // Player starting Y position
	char		spawn_dir;   // Initial direction (N/S/E/W)
	t_textures	*textures;  // Texture paths and colors
} t_map;

t_map	*init_map();

//Test parser
void		ft_parse_test(int argc, char **argv);
t_map		*get_test_map(void);
void		free_map(t_map *map);

//Get next line
int			holder_cleaner(char *holder, int clean);
char		*get_next_line(int fd, int clean);
char		*ft_read(int fd, int *char_read, char *temp);
char		*concat_line(char *line, char *str);
char		*get_next(char *holder, char *temp);
char		*cleaner(char *str, int before);
char		*nl_ft_strdup(char *str);
int			nl_ft_strlen(char *str);
int			has_line(char *str);
char		*str_alloc(int n);
char		*concat_str(char *str1, char *str2);

//Parser functions
t_map		*ft_parse(int argc, char **argv);
t_dll		*ft_get_file_content(int argc, char **argv);
int			ft_params_validator(int argc, char **argv);
void		ft_clean_file_content(t_dll *file_content);
int			ft_line_len(char *line);
t_map		*ft_process_map(t_dll *file_content);
t_textures	*ft_get_textures(t_dll *file_content);
void		ft_error_prc_map(t_map *map, t_dll *file_content, char *msg);
void		free_map(t_map *map);
void		ft_set_colors(t_textures *textures, t_dll *file_content);
char		*ft_remove_key(char *key, char *content);
int			ft_get_unique_key(char *key, t_dll *file_content);
char		*ft_get_key_content(char *key, t_dll *f_c);
t_dll		*ft_get_grid_content(t_dll *file_content);
void		ft_debug_file_content(t_dll *file_content);
bool		ft_valid_grid(t_dll *grid, t_map *map);
void		ft_set_grid(t_dll *file_content, t_map *map);
bool		ft_set_player_data(t_dll *grid_content, t_map *map);
bool		ft_check_zeros(t_dll *grid);
char		**ft_convert_to_str_array(t_dll *grid_content);
bool		ft_is_space(char c);

#endif