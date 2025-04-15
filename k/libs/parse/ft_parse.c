#include "ft_parse.h"

void ft_parse_test(int argc, char **argv)
{
	printf("Test function args count %d, map path %s", argc, argv[2]);
}

t_map *ft_parse(int argc, char **argv)
{
	t_map	*map;

	if (!ft_validator(argc, argv))
		return (NULL);

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
        for (int i = 0; i < map->rows; i++)
            free(map->grid[i]);
        free(map->grid);
    }
    if (map->textures)
    {
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