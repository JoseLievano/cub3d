/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:52:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/11 13:33:27 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*arr;

	space = count * size;
	if (size && (space / size) != count)
		return (NULL);
	arr = malloc(space);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, space);
	return (arr);
}
