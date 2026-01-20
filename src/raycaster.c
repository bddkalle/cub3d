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
void	wall_orientation(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	if ((int)px % BLOCK == 0 && cos(beta) > 0)
	{
		wall_slice->wall_orient = WEST;
		wall_slice->txt = &vars->map.we;
		wall_slice->offset = (int)py % BLOCK;
	}
	else if ((int)px % BLOCK == BLOCK - 1 && cos(beta) < 0)
	{
		wall_slice->wall_orient = EAST;
		wall_slice->txt = &vars->map.ea;
		wall_slice->offset = (int)py % BLOCK;
	}
	else if ((int)py % BLOCK == 0 && sin(beta) > 0)
	{
		wall_slice->wall_orient = NORTH;
		wall_slice->txt = &vars->map.no;
		wall_slice->offset = (int)px % BLOCK;
	}
	else if ((int)py % BLOCK == BLOCK - 1 && sin(beta) < 0)
	{
		wall_slice->wall_orient = SOUTH;
		wall_slice->txt = &vars->map.so;
		wall_slice->offset = (int)px % BLOCK;
	}
}

void	wall_info(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	wall_orientation(vars, wall_slice, px, py, beta);
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
	if (vars->map.grid[y][x] == '1') // was ist mit N,W,E,S etc.???
		return (true);
	else
		return (false);
}

void	draw_vertical_line(t_vars *vars, int ray_id, t_touch *wall_slice, bool draw_map)
{
	int		y;
	int		color;

	y = HEIGHT - 1;
	while (y >= 0)
	{
		if (draw_map && ray_id >= WIDTH / 4 * 3 && y >= HEIGHT / 4 * 3)
			y--;
		else if (y > wall_slice->wall_bottom)
			put_pixel(vars, ray_id, y--, create_rgb(vars->map.floor));
		else if (y > wall_slice->wall_top)
		{
			color = get_color_from_txt(vars, wall_slice, y);
			put_pixel(vars, ray_id, y--, color);
		}
		else
			put_pixel(vars, ray_id, y--, create_rgb(vars->map.ceiling));
	}
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
	wall_info(vars, &wall_slice, ray_x, ray_y, beta);
	//draw_vertical_line(vars, ray_x, ray_y, ray_id, beta);
	draw_vertical_line(vars, ray_id, &wall_slice, draw_map);
}
