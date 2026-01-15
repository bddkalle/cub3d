#include "../include/cub3D.h"

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

void	wall_projection(t_touch *slice)
{
	slice->wall_height = (BLOCK / slice->distance) * (WIDTH / 2.0) / tan(PI / 6);
	slice->wall_top = (HEIGHT - slice->wall_height) / 2;
	slice->wall_bottom = slice->wall_top + slice->wall_height;
}
