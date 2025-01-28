/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:20:12 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/03 23:25:00 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest < src)
	{
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			j = len - 1 - i;
			((unsigned char *)dest)[j] = ((unsigned char *)src)[j];
			i++;
		}
	}
	return (dest);
}
