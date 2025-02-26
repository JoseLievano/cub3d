/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:54:31 by jlievano          #+#    #+#             */
/*   Updated: 2025/02/26 04:54:32 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include "../../includes/cub3d.h"

typedef struct s_game		t_game;
typedef struct s_mlx		t_mlx;
typedef struct s_map		t_map;
typedef struct s_input		t_input;
typedef struct s_ray		t_ray;
typedef struct s_graphics	t_graphics;

void	ft_utils(void);
void	*ft_clean_game(t_game *game);
void	ft_clean_map(t_map *map);
void	ft_clean_input(t_input *input);
void	ft_clean_rays(t_ray *ray);
#endif
