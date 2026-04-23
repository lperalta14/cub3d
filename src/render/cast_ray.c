

#include "../../include/cubed.h"
 
static void	init_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*p;
 
	p = &game->player;
	ray->cam_x = 2.0 * x / WIN_W - 1.0;
	ray->rdx = p->dx + p->cx * ray->cam_x;
	ray->rdy = p->dy + p->cy * ray->cam_x;
	ray->map_x = (int)p->px;
	ray->map_y = (int)p->py;
	if (ray->rdx == 0)
		ray->ddx = 1e30;
	else
		ray->ddx = fabs(1.0 / ray->rdx);
	if (ray->rdy == 0)
		ray->ddy = 1e30;
	else
		ray->ddy = fabs(1.0 / ray->rdy);
	ray->hit = 0;
}
 
static void	init_step(t_game *game, t_ray *ray)
{
	t_player	*p;
 
	p = &game->player;
	if (ray->rdx < 0)
	{
		ray->step_x = -1;
		ray->sdx = (p->px - ray->map_x) * ray->ddx;
	}
	else
	{
		ray->step_x = 1;
		ray->sdx = (ray->map_x + 1.0 - p->px) * ray->ddx;
	}
	if (ray->rdy < 0)
	{
		ray->step_y = -1;
		ray->sdy = (p->py - ray->map_y) * ray->ddy;
	}
	else
	{
		ray->step_y = 1;
		ray->sdy = (ray->map_y + 1.0 - p->py) * ray->ddy;
	}
}
 
static void	dda_loop(t_game *game, t_ray *ray)
{
	char	**map;
 
	map = game->scene->map;
	while (ray->hit == 0)
	{
		if (ray->sdx < ray->sdy)
		{
			ray->sdx += ray->ddx;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sdy += ray->ddy;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y] && map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
 
static void	calc_column(t_game *game, t_ray *ray)
{
	t_player	*p;
 
	p = &game->player;
	if (ray->side == 0)
		ray->wall_dist = ray->sdx - ray->ddx;
	else
		ray->wall_dist = ray->sdy - ray->ddy;// mayor que cero
	ray->line_h = (int)(WIN_H / ray->wall_dist);
	ray->draw_start = WIN_H / 2 - ray->line_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = WIN_H / 2 + ray->line_h / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wall_x = p->py + ray->wall_dist * ray->rdy;
	else
		ray->wall_x = p->px + ray->wall_dist * ray->rdx;
	ray->wall_x -= floor(ray->wall_x);
}
 
void	cast_ray(t_game *game, t_ray *ray, int x)
{
	init_ray(game, ray, x);
	init_step(game, ray);
	dda_loop(game, ray);
	calc_column(game, ray);
	//if (x == WIN_W / 2)
	//	printf("wall_dist=%.2f side=%d map=(%d,%d) wall_x=%.2f\n", ray->wall_dist, ray->side, ray->map_x, ray->map_y, ray->wall_x);
} 