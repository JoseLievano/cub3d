#include "ft_parse.h"

static char	**ft_convert_to_str_array(t_dll *grid_content)
{
	char	**grid;
	size_t	lines;
	t_dll	*head;
	int		i;

	lines = t_dll_size(grid_content);
	grid = (char **)malloc(sizeof(char  *) * lines);
	head = t_dll_get_head(grid_content);
	i = 0;
	while (head)
	{
		grid[i] = ft_strdup((char *)head->content);
		head = head->next;
		i++;
	}
	t_dll_clear(grid_content, &ft_clean_file_content);
	return (grid);
}

char	**ft_get_grid(t_dll *file_content)
{
	t_dll	*grid_content;

	grid_content = ft_get_grid_content(file_content);
	if (!grid_content)
		return (NULL);
	if (!ft_valid_grid(grid_content))
	{
		t_dll_clear(grid_content, &ft_clean_file_content);
		return (NULL);
	}
	return (ft_convert_to_str_array(grid_content));
}

