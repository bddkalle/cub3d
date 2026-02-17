#include "../../include/cub3D.h"

t_wall	touch(t_vars *vars, double px, double py)
{
	int	x;
	int	y;

	x = (int)px / BLOCK;
	y = (int)py / BLOCK;
	if (x < 0 || y <0 || (t_size)y >= vars->map.g_h || (t_size)x >= vars->map.g_w)
		return (UNDET);
	if (vars->map.grid[y][x] == '1')
		return (TOUCH);
	else
		return (NOTOUCH);
}

void	first_horizontal_intersec(t_vars *vars, t_intrsec *wall_slice, double beta)
{
	t_fpoint	*tp;

	tp = &wall_slice->touchpoint;
	wall_slice->orient = HORIZONTAL;
	if (sin(beta) < 0)
		tp->y = (int)(vars->player.y / BLOCK) * BLOCK - 1e-6;
	else if (sin(beta) > 0)
		tp->y = (int)(vars->player.y / BLOCK) * BLOCK + BLOCK;
	else
	{
		tp->y = INFINITY;
		tp->x = vars->player.x;
		wall_slice->distance = INFINITY;
		wall_slice->touch = UNDET;
		return ;
	}
	tp->x = vars->player.x + (tp->y - vars->player.y) / tan(beta);
	wall_slice->distance = distance(tp->x - vars->player.x,\
		tp->y - vars->player.y);
	wall_slice->touch = touch(vars, wall_slice->touchpoint.x, wall_slice->touchpoint.y);
}

void	next_horizontal_intersec(t_vars *vars, t_intrsec *wall_slice, double beta)
{
	double	dx;
	double	dy;

	dx = BLOCK / tan(beta);
	dy = BLOCK;
	if (sin(beta) < 0)
		wall_slice->touchpoint.y -= dy;
	else if (sin(beta) > 0)
		wall_slice->touchpoint.y += dy;
	if (cos(beta) < 0)
		wall_slice->touchpoint.x -= absolute(dx);
	else if (cos(beta) > 0)
		wall_slice->touchpoint.x += absolute(dx);
	wall_slice->distance = distance(wall_slice->touchpoint.x - vars->player.x,\
		wall_slice->touchpoint.y - vars->player.y);
	wall_slice->touch = touch(vars, wall_slice->touchpoint.x, wall_slice->touchpoint.y);
}

void	first_vertical_intersec(t_vars *vars, t_intrsec *wall_slice, double beta)
{
	t_fpoint	*tp;

	tp = &wall_slice->touchpoint;
	wall_slice->orient = VERTICAL;
	if (cos(beta) < 0)
		tp->x = (int)(vars->player.x / BLOCK) * BLOCK - 1e-6;
	else if (cos(beta) > 0)
		tp->x = (int)(vars->player.x / BLOCK) * BLOCK + BLOCK;
	else
	{
		tp->x = INFINITY;
		tp->y = vars->player.y;
		wall_slice->distance = INFINITY;
		wall_slice->touch = UNDET;
		return ;
	}
	tp->y = vars->player.y + (tp->x - vars->player.x) * tan(beta);
	wall_slice->distance = distance(tp->x - vars->player.x,\
		tp->y - vars->player.y);
	wall_slice->touch = touch(vars, wall_slice->touchpoint.x, wall_slice->touchpoint.y);
}

void	next_vertical_intersec(t_vars *vars, t_intrsec *wall_slice, double beta)
{
	double	dx;
	double	dy;

	dx = BLOCK;
	dy = BLOCK * tan(beta);
	if (cos(beta) < 0)
		wall_slice->touchpoint.x -= dx;
	else if (cos(beta) > 0)
		wall_slice->touchpoint.x += dx;
	if (sin(beta) < 0)
		wall_slice->touchpoint.y -= absolute(dy);
	else if (sin(beta) > 0)
		wall_slice->touchpoint.y += absolute(dy);
	wall_slice->distance = distance(wall_slice->touchpoint.x - vars->player.x,\
		wall_slice->touchpoint.y - vars->player.y);
	wall_slice->touch = touch(vars, wall_slice->touchpoint.x, wall_slice->touchpoint.y);
}

