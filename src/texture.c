#include "../include/cub3D.h"


int	get_color_from_txt(t_vars *vars, t_touch *wall_slice, int y)
{
	char	*addr;
	int		index;
	int		color;

	(void)vars;
	(void)y;
	(void)index;
	y = y / HEIGHT * BLOCK;
	addr = wall_slice->txt->addr;
	index = y * wall_slice->txt->size_line + wall_slice->offset * (wall_slice->txt->bits_per_pixel / 8);
	color = (addr[index] & 0xFF) | ((addr[index + 1] & 0xFF) << 8) | ((addr[index + 2] & 0xFF) << 16) | ((addr[index + 3] & 0xFF) << 24);
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
	t_wall	wall;
	wall = touch(vars, ray_x, ray_y);
	printf("ray_x: %f | (int)rayx: %d | ray_x %% 64: %d\n", ray_x, (int)ray_x, (int)ray_x % 64);
	printf("ray_y: %f | (int)rayy: %d | ray_y %% 64: %d\n", ray_y, (int)ray_y, (int)ray_y % 64);
	printf("alpha: %f | cos(a): %f | sin(a): %f\n", vars->player.alpha, cos(vars->player.alpha), sin(vars->player.alpha));
	if (wall == NORTH)
		printf("NORTH\n");
	if (wall == EAST)
		printf("EAST\n");
	if (wall == SOUTH)
		printf("SOUTH\n");
	if (wall == WEST)
		printf("WEST\n");
	if (wall == FALSE)
		printf("FALSE\n");
}

