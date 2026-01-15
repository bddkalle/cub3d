#include "../include/cub3D.h"

/*
int	get_color_from_txt(t_txt *txt, float ray_x, float ray_y, float h)
{
	int	txt_px;
	int	txt_py;

	txt_px = ray_x - ((ray_x / BLOCK) * BLOCK);
	return (0);
}*/
/*
int		get_color_from_txt(t_vars *vars, t_wall_touch wall_touch, int y)
{
	int	color;


}*/

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
	t_wall_orient	wall;
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

