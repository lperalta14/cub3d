
 
#include "../../include/cubed_bonus.h"
 
static void	draw_cell(t_game *game, int px, int py, uint32_t color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
 
	dy = 0;
	while (dy < MINIMAP_SCALE)
	{
		dx = 0;
		while (dx < MINIMAP_SCALE)
		{
			sx = px + dx;
			sy = py + dy;
			if (sx >= 0 && sx < WIN_W && sy >= 0 && sy < WIN_H)
				mlx_put_pixel(game->img, sx, sy, color);
			dx++;
		}
		dy++;
	}
}
 
static uint32_t	get_cell_color(t_game *game, int map_x, int map_y)
{
	char	**map;
	int		lines;
 
	map = game->scene->map;
	lines = game->scene->map_lines;
	if (map_y < 0 || map_y >= lines)
		return (0x222222FF);
	if (!map[map_y] || map_x < 0 || map_x >= (int)ft_strlen(map[map_y]))
		return (0x222222FF);
	if (map[map_y][map_x] == '1')
		return (0x888888FF);
	return (0x444444FF);
}
 
static void	draw_player_dot(t_game *game, int origin_x, int origin_y)
{
	int	cx;
	int	cy;
	int	d;
 
	cx = origin_x + MINIMAP_RADIUS * MINIMAP_SCALE + MINIMAP_SCALE / 2;
	cy = origin_y + MINIMAP_RADIUS * MINIMAP_SCALE + MINIMAP_SCALE / 2;
	d = -2;
	while (d <= 2)
	{
		mlx_put_pixel(game->img, cx + d, cy, 0xFF0000FF);
		mlx_put_pixel(game->img, cx, cy + d, 0xFF0000FF);
		d++;
	}
}
 
void	draw_minimap(t_game *game)
{
	int	map_x;
	int	map_y;
	int	cell_x;
	int	cell_y;
	int	r;
 
	r = MINIMAP_RADIUS;
	cell_y = -r;
	while (cell_y <= r)
	{
		cell_x = -r;
		while (cell_x <= r)
		{
			map_x = (int)game->player.px + cell_x;
			map_y = (int)game->player.py + cell_y;
			draw_cell(game,
				10 + (cell_x + r) * MINIMAP_SCALE,
				10 + (cell_y + r) * MINIMAP_SCALE,
				get_cell_color(game, map_x, map_y));
			cell_x++;
		}
		cell_y++;
	}
	draw_player_dot(game, 10, 10);
}
 