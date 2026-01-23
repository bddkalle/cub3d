#include "../../include/cub3D.h"

float	absolute(float x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

t_wall	touch(t_vars *vars, float px, float py)
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

void	touch_horizontal(t_vars *vars, t_touch *wall_slice, float beta, int ray_id)
{
	t_fpoint	*tp;

	(void)ray_id;
	tp = &wall_slice->touchpoint;
	wall_slice->orient = HORIZONTAL;
	if (sin(beta) < 0)
		tp->y = (int)(vars->player.y / BLOCK) * BLOCK - 1;
	else if (sin(beta) > 0)
		tp->y = (int)(vars->player.y / BLOCK) * BLOCK + BLOCK;
	else
		wall_slice->distance = -1;
	if (sin(beta) != 0)
		tp->x = vars->player.x + (tp->y - vars->player.y) / tan(beta);
	else
		tp->x = vars->player.x;
	wall_slice->touch = touch(vars, tp->x, tp->y);
	float	dx;
	float	dy;

	dx = BLOCK / tan(beta);
	dy = BLOCK;

	while (wall_slice->touch == NOTOUCH)
	{
		if (sin(beta) < 0)
		{
			tp->y -= dy;
		}
		else
		{
			tp->y += dy;
		}
		if (cos(beta) < 0)
			tp->x -= absolute(dx);
		else
			tp->x += absolute(dx);
		wall_slice->touch = touch(vars, tp->x, tp->y);
	}
	wall_slice->distance = distance(tp->x - vars->player.x,\
		tp->y - vars->player.y);
}

void	touch_vertical(t_vars *vars, t_touch *wall_slice, float beta, int ray_id)
{
	t_fpoint	*tp;

	(void)ray_id;
	tp = &wall_slice->touchpoint;
	wall_slice->orient = VERTICAL;
	if (cos(beta) < 0)
		tp->x = (int)(vars->player.x / BLOCK) * BLOCK - 1;
	else if (cos(beta) > 0)
		tp->x = (int)(vars->player.x / BLOCK) * BLOCK + BLOCK;
	else
		wall_slice->distance = -1;
	if (cos(beta) != 0)
		tp->y = vars->player.y + (tp->x - vars->player.x) * tan(beta);
	else
		tp->y = vars->player.y;
	wall_slice->touch = touch(vars, tp->x, tp->y);
	float	dx;
	float	dy;
	dx = BLOCK;
	dy = BLOCK * tan(beta);
	while (wall_slice->touch == NOTOUCH)
	{
		if (cos(beta) < 0)
		{
			tp->x -= dx;
		}
		else
		{
			tp->x += dx;
		}
		if (sin(beta) < 0)
			tp->y -= absolute(dy);
		else
			tp->y += absolute(dy);
				wall_slice->touch = touch(vars, tp->x, tp->y);
	}
	wall_slice->distance = distance(tp->x - vars->player.x, tp->y - vars->player.y);
}

