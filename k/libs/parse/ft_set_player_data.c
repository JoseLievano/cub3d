#include "ft_parse.h"

static bool ft_check_row(size_t y, char *row, t_map *map)
{
	size_t x;

	x = 0;
	while (row[x])
	{
		if (row[x] == 'N' || row[x] == 'S' || row[x] == 'E' || row[x] == 'W')
		{
			if (map->spawn_dir != 'z')
				return (false);
			map->spawn_dir = row[x];
			map->spawn_x = (int)x;
			map->spawn_y = (int)y;
			row[x] = '0';
		}
		x++;
	}
	return (true);
}

bool ft_set_player_data(t_dll *grid, t_map *map)
{
	size_t	y;
	char	*row;
	t_dll	*head;

	map->spawn_dir = 'z';
	head = t_dll_get_head(grid);
	while (head)
	{
		y = (size_t)head->index;
		row = (char *) t_dll_get_node_index(grid, y)->content;
		if (!ft_check_row(y, row, map))
			return (false);
		head = head->next;
	}
	return (true);
}
