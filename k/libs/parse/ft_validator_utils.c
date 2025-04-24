/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:45:51 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:45:52 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_local_clean_map(map);
	t_dll_clear(file_content, &ft_clean_file_content);
	printf("Error : \n%s", msg);
	exit(EXIT_FAILURE);
}

void	ft_debug_file_content(t_dll *file_content)
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
