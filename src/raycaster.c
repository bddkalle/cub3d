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
void	wall_orientation(t_touch *wall_slice, float px, float py, float beta)
{
	if ((int)px % BLOCK == 0 && cos(beta) > 0)
	{
		wall_slice->wall_orient = WEST;
		wall_slice->offset = (int)py;
	}
	if ((int)px % BLOCK == BLOCK - 1 && cos(beta) < 0)
	{
		wall_slice->wall_orient = EAST;
		wall_slice->offset = BLOCK - (int)py;
	}
	if ((int)py % BLOCK == 0 && sin(beta) > 0)
	{
		wall_slice->wall_orient = NORTH;
		wall_slice->offset = (int)px;
	}
	if ((int)py % BLOCK == BLOCK - 1 && sin(beta) < 0)
	{
		wall_slice->wall_orient = SOUTH;
		wall_slice->offset = (int)py;
	}
}

void	wall_info(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	wall_orientation(wall_slice, px, py, beta);
	wall_slice->distance = correct_distance(
			vars,\
			distance(\
				px - vars->player.x,\
				py - vars->player.y),\
			beta);
	wall_projection(wall_slice);
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

void	draw_vertical_line(t_vars *vars, int ray_id, t_touch *touch)
{
	int		y;

	y = HEIGHT - 1;
	while (y > touch->wall_bottom)
		put_pixel(vars, ray_id, y--, create_rgb(vars->map.floor));
	while (y > touch->wall_top)
	{
		put_pixel(vars, ray_id, y--, 0x0000FF); //replace by texture
	}
	while (y >= 0)
		put_pixel(vars, ray_id, y--, create_rgb(vars->map.ceiling));
}

void	cast_ray(t_vars *vars, float beta, int ray_id, bool draw_map)
{
	float	ray_x;
	float	ray_y;
	t_touch	wall_slice;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		if (draw_map)
			put_pixel(vars, (int)ray_x / 4 + WIDTH / 4 * 3, (int)ray_y / 4 + HEIGHT / 4 * 3, 0xFF0000);
		ray_x += cos(beta);
		ray_y += sin(beta);
	}
	//wall_slice = malloc(sizeof(t_touch));
	wall_info(vars, &wall_slice, ray_x, ray_y, beta);
	//draw_vertical_line(vars, ray_x, ray_y, ray_id, beta);
	draw_vertical_line(vars, ray_id, &wall_slice);
	//free(wall_slice);
}
