/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:00 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:45:01 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../../includes/cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb;
	int		ceil_rgb;
}	t_textures;

typedef struct s_map
{
	char		**grid;
	int			rows;
	int			cols;
	int			spawn_x;
	int			spawn_y;
	char		spawn_dir;
	t_textures	*textures;
}	t_map;

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

t_map		*init_map(void);
t_map		*ft_parse(int argc, char **argv);
t_dll		*ft_get_file_content(int argc, char **argv);
int			ft_params_validator(int argc, char **argv);
void		ft_clean_file_content(t_dll *file_content);
int			ft_line_len(char *line);
t_map		*ft_process_map(t_dll *file_content);
t_textures	*ft_get_textures(t_dll *file_content);
void		ft_error_prc_map(t_map *map, t_dll *file_content, char *msg);
void		ft_set_colors(t_textures *textures, t_dll *file_content);
char		*ft_remove_key(char *key, char *content);
int			ft_get_unique_key(char *key, t_dll *file_content);
char		*ft_get_key_content(char *key, t_dll *f_c);
t_dll		*ft_get_grid_content(t_dll *file_content);
void		ft_debug_file_content(t_dll *file_content);
bool		ft_valid_grid(t_dll *grid);
void		ft_set_grid(t_dll *file_content, t_map *map);
bool		ft_set_player_data(t_dll *grid_content, t_map *map);
bool		ft_check_zeros(t_dll *grid);
char		**ft_convert_to_str_array(t_dll *grid_content);
bool		ft_is_space(char c);
void		ft_local_clean_map(t_map *map);
void		ft_debug_map(t_map *map);

#endif
