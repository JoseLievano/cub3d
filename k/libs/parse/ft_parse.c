#include "ft_parse.h"

void ft_debug_map(t_map *map)
{
	printf("------------------\n\n\nDEBUGGING MAP CONTENT\n");
	printf("Walls: \n");
	printf("NO: %s\n", map->textures->no_path);
	printf("SO: %s\n", map->textures->so_path);
	printf("WE: %s\n", map->textures->we_path);
	printf("EA: %s\n", map->textures->ea_path);
	printf("CEIL: %d\n", map->textures->ceil_rgb);
	printf("FLOOR: %d\n\n", map->textures->floor_rgb);
	printf("Map -----\n");
	printf("Rows : %d\n", map->rows);
	printf("Columns : %d\n", map->cols);
	printf("Spawn X: %d\n", map->spawn_x);
	printf("Spawn Y: %d\n", map->spawn_y);
	printf("Spawn dir: %c\n\n", map->spawn_dir);

	printf("Grid:\n");
	int i = 0;
	while (map->grid[i])
	{
		printf("[%s]\n", map->grid[i]);
		i++;
	}
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

static void	ft_set_col_row(t_map *map)
{
	int		i;
	int		k;
	int		c_c;
	char	*str;

	if (!map->grid)
		return ;
	i = 0;
	c_c = 0;
	while (map->grid[i])
	{
		k = 0;
		str = map->grid[i];
		while (str[k])
			k++;
		if (k > c_c)
			c_c = k;
		i++;
	}
	map->cols = c_c;
	map->rows = i;
}

static bool ft_final_map_validation(t_map *map)
{
	int fd;

	if ((fd = open(map->textures->no_path, O_RDONLY)) == -1)
		return (false);
	close(fd);
	if ((fd = open(map->textures->ea_path, O_RDONLY)) == -1)
		return (false);
	close(fd);
	if ((fd = open(map->textures->so_path, O_RDONLY)) == -1)
		return (false);
	close(fd);
	if ((fd = open(map->textures->we_path, O_RDONLY)) == -1)
		return (false);
	close(fd);
	if (!map->grid)
		return (false);
	if (!map->textures)
		return (false);
	return (true);
}

t_map *ft_parse(int argc, char **argv)
{
	t_map	*map;
	t_dll	*file_content;

	file_content = NULL;
	file_content = ft_get_file_content(argc, argv);
	map = ft_init_map();
	map->textures = ft_get_textures(file_content);
	ft_set_grid(file_content, map);
    ft_set_col_row(map);
	if (!ft_final_map_validation(map))
	{
		ft_local_clean_map(map);
		printf("Invalid .cub map :/\n");
		exit(1);
	}
	t_dll_clear(file_content, &ft_clean_file_content);
	return (map);
}
