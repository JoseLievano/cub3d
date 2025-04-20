#include "ft_parse.h"

void free_tab(void **tab)
{
	size_t i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int ft_get_valid_color_int(char *color_str)
{
	int color_i;

	color_i = ft_atoi(color_str);
	if (color_i < 0 || color_i > 255)
		return -1;
	return color_i;
}

static int parse_component(char *str)
{
	char *trimmed;
	int value;

	trimmed = ft_strtrim(str, " \t\n\r");
	if (!trimmed)
		return (-1);
	value = ft_get_valid_color_int(trimmed);
	free(trimmed);
	return (value);
}

static int ft_get_rgb(char *color_str)
{
	char **parts;
	int red;
	int green;
	int blue;

	if (!color_str)
		return (-1);
	parts = ft_split(color_str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (free_tab((void **) parts), -1);
	red = parse_component(parts[0]);
	green = parse_component(parts[1]);
	blue = parse_component(parts[2]);
	free_tab((void **) parts);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	return ((red << 16) | (green << 8) | blue);
}

void ft_set_colors(t_textures *textures, t_dll *file_content)
{
	char *floor;
	char *ceil;

	(void) textures;
	floor = ft_get_key_content("F", file_content);
	ceil = ft_get_key_content("C", file_content);
	printf("floor [%s]\nceil [%s]\n", floor, ceil);
	textures->ceil_rgb = ft_get_rgb(ceil);
	textures->floor_rgb = ft_get_rgb(floor);
	free(floor);
	free(ceil);
}
