/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:42:14 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:41:40 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	print_grid(t_vars *vars)
{
	t_point	p;

	printf("\n###### DEBUG ######\n\n");
	p = (t_point){};
	while (p.px_y < vars->map.g_h)
	{
		p.px_x = 0;
		while (p.px_x < vars->map.g_w)
		{
			printf("%c", vars->map.grid[p.px_y][p.px_x]);
			p.px_x++;
		}
		printf("\n");
		p.px_y++;
	}
	printf("\n###### END DEBUG ######\n\n");
}
