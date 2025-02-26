/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:40:02 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 02:40:03 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void	ft_put_pixel(int x, int y, unsigned int pixel, t_img *img)
{
	unsigned int	offset;

	offset = (img->size_line * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->data)) = pixel;
}

void	ft_clear_frame(t_graphics *gfx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < MAX_H)
	{
		x = 0;
		while (x < MAX_W)
		{
			ft_put_pixel(x, y, 0x000000, gfx->frame);
			x++;
		}
		y++;
	}
}
