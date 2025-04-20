#include "ft_parse.h"

void	ft_clean_file_content(t_dll *file_content)
{
	free(file_content->content);
}

int	ft_line_len(char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_error_prc_map(t_map *map, t_dll *file_content, char *msg)
{
	free_map(map);
	t_dll_clear(file_content, &ft_clean_file_content);
	printf("Error : \n%s", msg);
	exit(EXIT_FAILURE);
}

