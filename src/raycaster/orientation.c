/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:50:58 by vboxuser          #+#    #+#             */
/*   Updated: 2026/02/18 15:34:42 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	decide_so_we(t_vars *vars, t_intrsec *wall_slice)
{
	if (wall_slice->orient == HORIZONTAL)
	{
		wall_slice->txt = &vars->map.so;
		wall_slice->offset = (int)wall_slice->touchpoint.x % BLOCK;
	}
	else
	{
		wall_slice->txt = &vars->map.we;
		wall_slice->offset = (int)wall_slice->touchpoint.y % BLOCK;
	}
}

void	decide_so_ea(t_vars *vars, t_intrsec *wall_slice)
{
	if (wall_slice->orient == HORIZONTAL)
	{
		wall_slice->txt = &vars->map.so;
		wall_slice->offset = (int)wall_slice->touchpoint.x % BLOCK;
	}
	else
	{
		wall_slice->txt = &vars->map.ea;
		wall_slice->offset = BLOCK - 1 - (int)wall_slice->touchpoint.y % BLOCK;
	}
}

void	decide_no_we(t_vars *vars, t_intrsec *wall_slice)
{
	if (wall_slice->orient == HORIZONTAL)
	{
		wall_slice->txt = &vars->map.no;
		wall_slice->offset = BLOCK - 1 - (int)wall_slice->touchpoint.x % BLOCK;
	}
	else
	{
		wall_slice->txt = &vars->map.we;
		wall_slice->offset = (int)wall_slice->touchpoint.y % BLOCK;
	}
}

void	decide_no_ea(t_vars *vars, t_intrsec *wall_slice)
{
	if (wall_slice->orient == HORIZONTAL)
	{
		wall_slice->txt = &vars->map.no;
		wall_slice->offset = BLOCK - 1 - (int)wall_slice->touchpoint.x % BLOCK;
	}
	else
	{
		wall_slice->txt = &vars->map.ea;
		wall_slice->offset = BLOCK - 1 - (int)wall_slice->touchpoint.y % BLOCK;
	}
}

void	wall_orientation(t_vars *vars, t_intrsec *wall_slice)
{
	if (vars->player.y > wall_slice->touchpoint.y \
			&& vars->player.x > wall_slice->touchpoint.x)
		decide_so_ea(vars, wall_slice);
	else if (vars->player.y > wall_slice->touchpoint.y \
			&& vars->player.x < wall_slice->touchpoint.x)
		decide_so_we(vars, wall_slice);
	else if (vars->player.y <= wall_slice->touchpoint.y \
			&& vars->player.x >= wall_slice->touchpoint.x)
		decide_no_ea(vars, wall_slice);
	else if (vars->player.y <= wall_slice->touchpoint.y \
			&& vars->player.x <= wall_slice->touchpoint.x)
		decide_no_we(vars, wall_slice);
}
