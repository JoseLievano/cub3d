/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grid_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:43:48 by jlievano          #+#    #+#             */
/*   Updated: 2025/04/24 12:43:49 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static bool	ft_is_limit(char *line)
{
	size_t	len;
	size_t	i;
	int		count;

	i = 0;
	len = ft_strlen(line);
	count = 0;
	while (i < len)
	{
		if (line[i] != ' ' && line[i] != '1')
			return (false);
		if (line[i] == '1')
			count++;
		i++;
	}
	if (count > 0)
		return (true);
	return (false);
}

static int	get_first_index(t_dll *file_content)
{
	int		index;
	t_dll	*temp;
	char	*str;

	temp = file_content;
	str = NULL;
	index = -1;
	while (temp)
	{
		str = (char *) temp->content;
		if (ft_is_limit(str))
		{
			index = temp->index;
			break ;
		}
		temp = temp->next;
	}
	return (index);
}

static int	get_last_index(t_dll *file_content)
{
	int		index;
	t_dll	*temp;
	char	*str;

	temp = t_dll_get_tail(file_content);
	str = NULL;
	index = -1;
	while (temp)
	{
		str = (char *) temp->content;
		if (ft_is_limit(str))
		{
			index = temp->index;
			break ;
		}
		temp = temp->prev;
	}
	return (index);
}

static t_dll	*ft_clone_node(t_dll *node)
{
	t_dll	*clone;
	char	*temp_str;

	temp_str = (char *)node->content;
	clone = (t_dll *)malloc(sizeof(t_dll));
	clone->index = 0;
	clone->prev = NULL;
	clone->next = NULL;
	clone->content = ft_strdup(temp_str);
	return (clone);
}

t_dll	*ft_get_grid_content(t_dll *file_content)
{
	int	s_i;
	int	l_i;

	s_i = get_first_index(file_content);
	l_i = get_last_index(file_content);
	if ((s_i == -1 || l_i == -1) || (s_i == l_i) || (l_i - s_i < 2))
		return (NULL);
	return (t_dll_clone_range(file_content, s_i, l_i, &ft_clone_node));
}
