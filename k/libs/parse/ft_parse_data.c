/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores- <vflores-@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:18:27 by vflores-          #+#    #+#             */
/*   Updated: 2025/03/18 15:34:50 by vflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

//Cuenta la cantidad de lineas en un archivo de texto
static int	count_number_of_lines(char *path)
{
	int		fd;
	char	*cur;
	int		total_lines;

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

	line = get_next_line(data->mapinfo.fd);
	while (line)
	{
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapinfo.file[row])
		{
			error_msg(NULL, ERR_MALLOC, 0);
			free_tab((void **)data->mapinfo.file);
			return ;
		}
		while (line[i] != '\0')
			data->mapinfo.file[row][col++] = line[i];
		data->mapinfo.file[row][col] = '\0';
		col = 0;
		i = 0;
		row++;
		free(line);
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.file[row] = NULL;
}

/* Se encarga de leer los datos de un archivo y almacenarlos en la estructura
 * t_data dentro de data->map.file. Se usa principalmente para cargar un mapa 
 * en un moto de graficos basado en texto.
 */
void	parse_data(char *path, t_data *dt)
{
	int		cur_row;
	int		i;
	size_t	cur_col;

	cur_row = 0;
	i = 0;
	cur_col = 0;
	dt->mapinfo.line_count = count_number_of_lines(path);
	dt->mapinfo.path = path;
	dt->mapinfo.file = ft_calloc(dt->mapinfo.line_count + 1, sizeof(char *));
	if (!dt->mapinfo.file)
	{
		error_msg(NULL, ERR_MALLOC, 0);
		return ;
	}
	dt->mapinfo.fd = open(path, O_RDONLY);
	if (dt->mapinfo.fd < 0)
	{
		error_msg(path, strerror(errno), FAILURE);
		return ;
	}
	fill_map(cur_row, cur_col, i, dt);
	close(dt->mapinfo.fd);
}
