#include "../include/cub3D.h"

// linear mapping from screen renderer to texture, solve linear equation system using 1. wall_bottom -> (px_h - 1) 2. wall_top -> 0
int	y_texture_mapping(t_touch *wall_slice, int y)
{
	float	a;
	float	b;
	int	txt_y;

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
	//if (wall_slice->offset == 0)
	//	color = 0x00FF00;
	return (color);
}

void	wall_detector_helper(t_vars *vars)
{
	float	ray_x;
	float	ray_y;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		ray_x += cos(vars->player.alpha);
		ray_y += sin(vars->player.alpha);
	}
	t_touch	wall_slice;
	wall_info(vars, &wall_slice, ray_x, ray_y, vars->player.alpha);
	printf("texture_h: %d, texture_w: %d\n", wall_slice.txt->px_h, wall_slice.txt->px_w);
	printf("ray_x: %f | (int)rayx: %d | ray_x %% 64: %d\n", ray_x, (int)ray_x, (int)ray_x % 64);
	printf("ray_y: %f | (int)rayy: %d | ray_y %% 64: %d\n", ray_y, (int)ray_y, (int)ray_y % 64);
	printf("alpha: %f | cos(a): %f | sin(a): %f\n", vars->player.alpha, cos(vars->player.alpha), sin(vars->player.alpha));
	if (wall_slice.wall_orient == NORTH)
		printf("NORTH\n");
	if (wall_slice.wall_orient == EAST)
		printf("EAST\n");
	if (wall_slice.wall_orient == SOUTH)
		printf("SOUTH\n");
	if (wall_slice.wall_orient == WEST)
		printf("WEST\n");
	if (wall_slice.wall_orient == FALSE)
		printf("FALSE\n");
}

