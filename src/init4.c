/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:04:39 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/16 11:39:40 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_img_addr(t_vars *vars, char *line, int fd, t_txt txt)
{
	txt.addr = mlx_get_data_addr(txt.img, &txt.bits_per_pixel, \
	&txt.size_line, &txt.endian);
	if (!txt.addr || txt.bits_per_pixel <= 0 || txt.size_line <= 0)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Could not set image address for texture", \
	"Error\nmlx_get_data_addr");
	}
}
