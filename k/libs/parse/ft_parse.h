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
void	ft_parse_test(int argc, char **argv);
t_map	*get_test_map(void);
void	free_map(t_map *map);

//Get next line
int		holder_cleaner(char *holder, int clean);
char	*get_next_line(int fd, int clean);
char	*ft_read(int fd, int *char_read, char *temp);
char	*concat_line(char *line, char *str);
char	*get_next(char *holder, char *temp);
char	*cleaner(char *str, int before);
char	*nl_ft_strdup(char *str);
int		nl_ft_strlen(char *str);
int		has_line(char *str);
char	*str_alloc(int n);
char	*concat_str(char *str1, char *str2);

//Parser functions
t_map	*ft_parse(int argc, char **argv);
bool	ft_validator(int argc, char **argv);
int		ft_params_validator(int argc, char **argv);


#endif