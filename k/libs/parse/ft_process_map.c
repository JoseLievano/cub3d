#include "ft_parse.h"

t_map	*ft_process_map(t_dll *file_content)
{
	t_map		*map;
	t_textures	*textures;

	map = malloc(sizeof(t_map *));
	textures = ft_get_textures(file_content);
	if (!textures)
		ft_error_prc_map(map, file_content, "Textures not loaded\n");
	map->textures = textures;
	return (map);
}