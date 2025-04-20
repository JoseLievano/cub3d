#include "ft_parse.h"

static void ft_set_textures(t_textures *textures, t_dll *file_content)
{
	textures->no_path = ft_get_key_content("NO", file_content);
	textures->so_path = ft_get_key_content("SO", file_content);
	textures->we_path = ft_get_key_content("WE", file_content);
	textures->ea_path = ft_get_key_content("EA", file_content);
}

t_textures	*ft_init_textures(void)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->ceil_rgb = -1;
	textures->floor_rgb = -1;
	textures->no_path = NULL;
	textures->ea_path = NULL;
	textures->we_path = NULL;
	textures->so_path = NULL;
	return (textures);
}

t_textures *ft_get_textures(t_dll *file_content)
{
	t_textures *textures;

	textures = ft_init_textures();
	if (!textures)
		return NULL;
	ft_set_textures(textures, file_content);
	ft_set_colors(textures, file_content);
	return textures;
}
