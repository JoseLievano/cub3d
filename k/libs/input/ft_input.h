/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:43:27 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 03:43:28 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INPUT_H
# define FT_INPUT_H
# include "../../includes/cub3d.h"

typedef struct s_game	t_game;

typedef struct s_input
{
	bool	up;
	bool	right;
	bool	down;
	bool	left;
	bool	r_l;
	bool	r_r;
	bool	esc;
	int		mouse_x;
}	t_input;

t_input	*ft_input_init(void);
#endif
