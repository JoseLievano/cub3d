/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:18:27 by vflores-          #+#    #+#             */
/*   Updated: 2025/02/19 17:40:48 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

//Cuenta la cantidad de lineas en un archivo de texto
static int	count_number_of_lines(char *path)
{
	int	fd;
	char	*cur;
	int	total_lines;

	total_lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		error_msg(path, strerror(errno), errno);
		return (0);
	}
	cur = get_next_line(fd);
	while (cur)
	{
		total_lines++;
		free(cur);
		cur = get_next_line(fd);
	}
	close(fd);
	return (total_lines);
}

// Lee lineas de un archivo y las almacena en un array de strings
static void	fill_map(int row, int col, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line)
	{
		data->map.fd[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.file[row])
		{
			error_msg(NULL, ERR_MALLOC, 0);
			free_tab((void **)data->map.file);
			return ;
		}
		while (line[i] != '\0')
			data->map.file[row][col++] = line[i];
		data->map.file[row][col] = '\0';
		col = 0;
		i = 0;
		row++;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.file[row] = NULL;
}

/* Se encarga de leer los datos de un archivo y almacenarlos en la estructura
 * t_data dentro de data->map.file. Se usa principalmente para cargar un mapa 
 * en un moto de graficos basado en texto.
 */
void	parse_data(char *path, t_data *data)
{
	int	cur_row;
	int	i;
	size_t	cur_col;

	cur_row = 0;
	i = 0;
	cur_col = 0;
	data->map.line_count = count_number_of_lines(path);
	data->map.path = path;
	data->map.file = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!data->map.file)
	{
		error_msg(NULL, ERR_MALLOC, 0);
		return ;
	}
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
	{
		error_msg(path, strerror(errno), FAILURE);
		return ;
	}
	fill_map(cur_row, cur_col, i, data);
	close(data->map.fd);
}
