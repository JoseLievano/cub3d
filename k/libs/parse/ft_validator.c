#include "ft_parse.h"

static void	debug_file_content(t_dll *file_content)
{
	int		i;
	char	*current_line;
	int		len;

	i = 0;
	len = (int)t_dll_size(file_content);
	printf("lines : %d\n", len);
	while (i < len)
	{
		current_line = (char *)t_dll_get_node_index(file_content, i)->content;
		printf("%s\n", current_line);
		i++;
	}
}

static char	*clean_line(char *line)
{
	char	*new_line;
	int		i;

	new_line = (char *)malloc(sizeof(char) * (ft_line_len(line) + 1));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	new_line[i] = '\0';
	return (new_line);
}

static t_dll	*get_file_content(int fd)
{
	t_dll	*file_content;
	char	*line;

	file_content = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		line = clean_line(line);
		t_dll_add_back(&file_content, t_dll_new(line));
	}
	close(fd);
	return (file_content);
}

t_dll *ft_get_file_content(int argc, char **argv)
{
	int		fd;
	t_dll	*file_content;

	fd = ft_params_validator(argc, argv);
	file_content = get_file_content(fd);
	debug_file_content(file_content);
	return (file_content);
}