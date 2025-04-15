#include "ft_parse.h"

char	*cleaner(char *str, int before)
{
	char	*new_str;
	int		mem_space;
	int		i;
	int		j;

	i = 0;
	if (before == 1)
	{
		mem_space = sizeof(char) * (has_line(str) + 2);
		j = 0;
	}
	else
	{
		mem_space = sizeof(char) * (nl_ft_strlen(str) - has_line(str));
		j = has_line(str) + 1;
	}
	new_str = str_alloc(mem_space);
	while (i < (mem_space - 1))
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (new_str);
}

char	*get_next(char *holder, char *temp)
{
	char	*new_h;

	if (!holder && !temp)
		return (NULL);
	if (!holder)
		holder = str_alloc(1);
	if (!temp)
		temp = str_alloc(1);
	new_h = concat_str(holder, temp);
	free(holder);
	free(temp);
	if (nl_ft_strlen(new_h) <= 0 || has_line(new_h) < 0)
	{
		free(new_h);
		return (NULL);
	}
	new_h = cleaner(new_h, 0);
	return (new_h);
}

char	*concat_line(char *line, char *str)
{
	char	*new_str;

	if (!line && !str)
		return (NULL);
	if (!line)
		line = str_alloc(1);
	if (!str)
		str = str_alloc(1);
	new_str = concat_str(line, str);
	if (line)
		free(line);
	if (nl_ft_strlen(str) == 0)
		free(str);
	if (nl_ft_strlen(new_str) == 0)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}

char	*ft_read(int fd, int *char_read, char *temp)
{
	char	*new_temp;

	if (temp)
		free(temp);
	*char_read = 0;
	new_temp = str_alloc(BUFFER_SIZE + 1);
	*char_read = read(fd, new_temp, BUFFER_SIZE);
	if (*char_read <= 0 || nl_ft_strlen(new_temp) == 0)
	{
		free(new_temp);
		*char_read = 0;
		return (NULL);
	}
	return (new_temp);
}

char	*get_next_line(int fd, int clean)
{
	static char	*holder;
	char		*temp;
	char		*line;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || holder_cleaner(holder, clean))
		return (NULL);
	line = NULL;
	temp = NULL;
	if (nl_ft_strlen(holder) > 0)
		line = nl_ft_strdup(holder);
	char_read = 1;
	while (char_read > 0)
	{
		temp = ft_read(fd, &char_read, temp);
		if (temp)
			line = concat_line(line, temp);
		if (has_line(line) >= 0)
			break ;
	}
	if (has_line(line) >= 0)
		line = cleaner(line, 1);
	holder = get_next(holder, temp);
	return (line);
}
