/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:42 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:45:43 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

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

t_dll	*ft_get_file_content(int argc, char **argv)
{
	int		fd;
	t_dll	*file_content;

	fd = ft_params_validator(argc, argv);
	file_content = get_file_content(fd);
	return (file_content);
}
