/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:37 by vflores-          #+#    #+#             */
/*   Updated: 2024/04/05 15:33:44 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read_rest_str: read dates from the fd, save them in a buffer
//and makes a security copy of the read dates in other buffer.
//extract_line: extract some of the line until it founds the
//character for new line '\n'.
#include "get_next_line.h"

static char	*extract_line(char *line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = '\0';
	return (temp);
}

static char	*read_rest_str(int fd, char *buf, char *copy)
{
	char	*temp;
	int		rd_line;

	rd_line = 1;
	while (rd_line != '\0')
	{
		rd_line = read(fd, buf, BUFFER_SIZE);
		if (rd_line == -1)
			return (0);
		else if (rd_line == 0)
			break ;
		buf[rd_line] = '\0';
		if (!copy)
			copy = ft_strdup("");
		temp = copy;
		copy = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (copy);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*prev_line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_rest_str(fd, buf, prev_line);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	prev_line = extract_line(line);
	return (line);
}
