
#include "../../include/cubed_bonus.h"
 
void	render_frame(void *param)
{
	t_game	*game;
	t_ray	ray;
	int		x;
 
	game = (t_game *)param;
	handle_input(game);
	draw_floor_ceiling(game);
	x = 0;
	while (x < WIN_W)
	{
		cast_ray(game, &ray, x);
		draw_column(game, &ray, x);
		x++;
	}
	draw_minimap(game);
}
 