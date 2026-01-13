#include "../include/cub3D.h"

/*
t_wall_orient	wall_orient(t_vars *vars, float px, float py)
{
	if ((int)py % BLOCK == 0 && (int)px % BLOCK != 0)
	{
		if (cos(vars->player.alpha) < 0)
			return (NORTH);
		if (cos(vars->player.alpha) > 0)
			return (SOUTH);
	}
	else if ((int)px % BLOCK == 0 && (int)px % BLOCK != 0)
	{
		if (sin(vars->player.alpha) > 0)
			return (WEST);
		if (sin(vars->player.alpha) < 0)
			return (EAST);
	}
	return (UNDET);
}
*/
t_wall_orient	wall_orient(t_vars *vars, float px, float py)
{
	(void)vars;
	if ((int)px % BLOCK == 0)
		return(WEST);
	if ((int)px % BLOCK == 63)
		return(EAST);
	if ((int)py % BLOCK == 0)
		return(NORTH);
	if ((int)py % BLOCK == 63)
		return(SOUTH);
	return (UNDET);
}

t_wall_orient	touch(t_vars *vars, float px, float py)
{
	int	x;
	int y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (vars->map.grid[y][x] == '0')
		return (FALSE);
	else
		return (wall_orient(vars, px, py));
}

float	distance(float dx, float dy)
{
	return (sqrt(dx * dx + dy * dy));
}

// draw verital line, scale obstacle by distance, correct distance to avoid fisheye distortion
// fisheye correction: 1. angular distance of alpha and beta 2. triangle: cos(beta - alpha) * dist_dist = corr_dist
// calculated projected height h of Wall with real height BLOCK: using tan(FOV/2) = 1/2 * WIDTH / distanceToProjectionScreen

float	correct_distance(t_vars *vars, float dist_d, float beta)
{
	return (dist_d * cos(beta - vars->player.alpha));
}

void	draw_vertical_line(t_vars *vars, float ray_x, float ray_y, int ray, float beta)
{
	float	d;
	float	h;
	int		bottom;
	int		top;

	d = correct_distance(
			vars,\
			distance(\
				ray_x - vars->player.x,\
				ray_y - vars->player.y),\
			beta);
	h = (BLOCK / d) * (WIDTH / 2.0) / tan(PI / 6);
	bottom = (HEIGHT - h) / 2;
	top = bottom + h;
	while (bottom < top)
	{
		put_pixel(vars, ray, bottom, 0x0000FF);
		bottom++;
	}
}

void	cast_ray(t_vars *vars, float beta, int ray, bool draw_map)
{
	float	ray_x;
	float	ray_y;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		if (draw_map)
			put_pixel(vars, (int)ray_x / 4 + WIDTH / 4 * 3, (int)ray_y / 4 + HEIGHT / 4 * 3, 0xFF0000);
		ray_x += cos(beta);
		ray_y += sin(beta);
	}
	draw_vertical_line(vars, ray_x, ray_y, ray, beta);
}
