#include "ft_parse.h"

static void clean_textures(t_textures *textures)
{
	if (!textures)
		return;
	if (textures->no_path)
		free(textures->no_path);
	if (textures->so_path)
		free(textures->so_path);
	if (textures->we_path)
		free(textures->we_path);
	if (textures->ea_path)
		free(textures->ea_path);
	free(textures);
}

void ft_local_clean_map(t_map *map)
{
	int i;

	if (!map)
		return;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->textures)
		clean_textures(map->textures);
	free(map);
}

void ft_parse_test(int argc, char **argv)
{
	printf("Test function args count %d, map path %s", argc, argv[2]);
}

void ft_debug_map(t_map *map)
{
	printf("Walls: \n");
	printf("NO: %s\n", map->textures->no_path);
	printf("SO: %s\n", map->textures->so_path);
	printf("WE: %s\n", map->textures->we_path);
	printf("EA: %s\n", map->textures->ea_path);
	printf("CEIL: %d\n", map->textures->ceil_rgb);
	printf("FLOOR: %d\n", map->textures->floor_rgb);
}

t_map	*ft_init_map()
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	map->textures = NULL;
	map->grid = NULL;
	map->rows = -1;
	map->cols = -1;
	map->spawn_dir = 'x';
	map->spawn_x = -1;
	map->spawn_y = -1;
	return (map);
}

t_map *ft_parse(int argc, char **argv)
{
	t_map	*map;
	t_dll	*file_content;
	t_dll	*grid_content;

	file_content = NULL;
	file_content = ft_get_file_content(argc, argv);
	map = ft_init_map();
	map->textures = ft_get_textures(file_content);
	ft_debug_map(map);
	grid_content = ft_get_grid_content(file_content);
	ft_debug_file_content(grid_content);
	t_dll_clear(grid_content, &ft_clean_file_content);
	t_dll_clear(file_content, &ft_clean_file_content);
	ft_local_clean_map(map);
	return (map);
}

/*
 * Helper function to free the map structure.
 */
void free_map(t_map *map)
{
	if (!map)
		return;
	if (map->grid)
	{
		printf("Cleaning grid\n");
		for (int i = 0; i < map->rows; i++)
			free(map->grid[i]);
		free(map->grid);
	}
	if (map->textures)
	{
		printf("Cleaning textures\n");
		free(map->textures->no_path);
		free(map->textures->so_path);
		free(map->textures->we_path);
		free(map->textures->ea_path);
		free(map->textures);
	}
	free(map);
}

t_map *get_test_map(void)
{
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return NULL;

	// Set dimensions for the grid
	map->rows = 7;
	map->cols = 7;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
	{
		free(map);
		return NULL;
	}

	char *grid_data[] = {
		"1111111111",
		"1001000001",
		"1001000001",
		"1000001001",
		"1000001001",
		"1000N00001",
		"1111111111"
	};

	for (int i = 0; i < map->rows; i++)
	{
		map->grid[i] = strdup(grid_data[i]);
		if (!map->grid[i])
		{
			free_map(map);
			return NULL;
		}
	}

	// Set spawn position and direction
	map->spawn_x = 4;
	map->spawn_y = 4;
	map->spawn_dir = 'W';

	// Allocate and initialize textures
	map->textures = malloc(sizeof(t_textures));
	if (!map->textures)
	{
		free_map(map);
		return NULL;
	}

	map->textures->no_path = strdup("textures/wall_1.xpm");
	map->textures->so_path = strdup("textures/wall_2.xpm");
	map->textures->we_path = strdup("textures/wood.xpm");
	map->textures->ea_path = strdup("textures/wood.xpm");

	if (!map->textures->no_path || !map->textures->so_path ||
		!map->textures->we_path || !map->textures->ea_path)
	{
		free_map(map);
		return NULL;
	}

	// Set RGB values
	map->textures->ceil_rgb = 0x2446bf;
	map->textures->floor_rgb = 0x66290e;

	return map;
}
