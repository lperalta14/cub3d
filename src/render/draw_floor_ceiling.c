
#include "../../include/cubed.h"
 
static uint32_t	int_to_rgba(int color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
 
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
 
void	draw_floor_ceiling(t_game *game)
{
	uint32_t	ceil_color;
	uint32_t	floor_color;
	int			x;
	int			y;
 
	ceil_color = int_to_rgba(game->scene->ceiling);
	floor_color = int_to_rgba(game->scene->floor);
	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x, y, ceil_color);
			x++;
		}
		y++;
	}
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x, y, floor_color);
			x++;
		}
		y++;
	}
}
 