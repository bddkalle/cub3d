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

/* wall orientation is determined by rounding down ray coordinates when grid=1 is touched.
For edge cases it is necessary to check wether angle is left/right or up/down */
t_wall_touch	wall_info(t_vars *vars, float px, float py, float beta)
{
	t_wall_touch	wall_touch;
	(void)vars;
	if ((int)px % BLOCK == 0 && cos(beta) > 0)
	{
		wall_touch.wall_orient = WEST;
		wall_touch.offset = (int)py;
	}
	if ((int)px % BLOCK == BLOCK - 1 && cos(beta) < 0)
	{
		wall_touch.wall_orient = EAST;
		wall_touch.offset = BLOCK - (int)py;
	}
	if ((int)py % BLOCK == 0 && sin(beta) > 0)
	{
		wall_touch.wall_orient = NORTH;
		wall_touch.offset = (int)px;
	}
	if ((int)py % BLOCK == BLOCK - 1 && sin(beta) < 0)
	{
		wall_touch.wall_orient = SOUTH;
		wall_touch.offset = (int)py;
	}
	return (wall_touch);
}

bool	touch(t_vars *vars, float px, float py)
{
	int	x;
	int y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (vars->map.grid[y][x] == '0')
		return (false);
	else
		return (true);
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
/*
void	draw_vertical_line(t_vars *vars, float ray_x, float ray_y, int ray_id, float beta)
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
		put_pixel(vars, ray_id, bottom, 0x0000FF);
		bottom++;
	}
}
*/

void	draw_vertical_line(t_vars *vars, int ray_id, float dist, t_wall_touch wall_touch)
{
	float	wall_height;
	int		wall_bottom;
	int		wall_top;
	int		y;
	int		color[3];

	(void)wall_touch;
	wall_height = (BLOCK / dist) * (WIDTH / 2.0) / tan(PI / 6);
	wall_top = (HEIGHT - wall_height) / 2;
	wall_bottom = wall_top + wall_height;
	y = HEIGHT - 1;
	while (y > wall_bottom)
		put_pixel(vars, ray_id, y--, create_rgb(vars->map.floor));
	while (y > wall_top)
	{
		put_pixel(vars, ray_id, y--, create_rgb(color)); //replace by texture
	}
	while (y >= 0)
		put_pixel(vars, ray_id, y--, create_rgb(vars->map.ceiling));
}

void	cast_ray(t_vars *vars, float beta, int ray_id, bool draw_map)
{
	float			ray_x;
	float			ray_y;
	float			dist;
	t_wall_touch	wall_touch;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		if (draw_map)
			put_pixel(vars, (int)ray_x / 4 + WIDTH / 4 * 3, (int)ray_y / 4 + HEIGHT / 4 * 3, 0xFF0000);
		ray_x += cos(beta);
		ray_y += sin(beta);
	}
	dist = correct_distance(
			vars,\
			distance(\
				ray_x - vars->player.x,\
				ray_y - vars->player.y),\
			beta);
	wall_touch = wall_info(vars, ray_x, ray_y, beta);
	//draw_vertical_line(vars, ray_x, ray_y, ray_id, beta);
	draw_vertical_line(vars, ray_id, dist, wall_touch);
}
