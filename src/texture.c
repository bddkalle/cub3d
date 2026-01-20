/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:29:32 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 20:13:30 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// linear mapping from screen renderer to texture, solve linear equation system using 1. wall_bottom -> (px_h - 1) 2. wall_top -> 0
int	y_texture_mapping(t_touch *wall_slice, int y)
{
	float	a;
	float	b;
	int		txt_y;

	a = ((float)wall_slice->txt->px_h - 1) / (wall_slice->wall_bottom - wall_slice->wall_top);
	b = a * wall_slice->wall_top * (-1);
	txt_y = a * y + b;
	return (txt_y);
}

int	get_color_from_txt(t_vars *vars, t_touch *wall_slice, int y)
{
	char	*addr;
	int		index;
	int		color;
	int		txt_y;

	(void)vars;
	txt_y = y_texture_mapping(wall_slice, y);
	addr = wall_slice->txt->addr;
	index = txt_y * wall_slice->txt->size_line + wall_slice->offset * (wall_slice->txt->bits_per_pixel / 8);
	color = (addr[index] & 0xFF) | ((addr[index + 1] & 0xFF) << 8) | ((addr[index + 2] & 0xFF) << 16) | ((addr[index + 3] & 0xFF) << 24);
	return (color);
}

