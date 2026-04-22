
#include "../../include/cubed.h"

static void	set_dir_north(t_player *p)
{
	p->dx = 0;
	p->dy = -1;
	p->cx = 0.66;
	p->cy = 0;
}
 
static void	set_dir_south(t_player *p)
{
	p->dx = 0;
	p->dy = 1;
	p->cx = -0.66;
	p->cy = 0;
}
 
static void	set_dir_east(t_player *p)
{
	p->dx = 1;
	p->dy = 0;
	p->cx = 0;
	p->cy = 0.66;
}
 
static void	set_dir_west(t_player *p)
{
	p->dx = -1;
	p->dy = 0;
	p->cx = 0;
	p->cy = -0.66;
}
 
void	init_player(t_game *game)
{
	t_player	*p;
	t_position	*pos;
 
	p = &game->player;
	pos = &game->scene->play_post;
	p->px = pos->x + 0.5;
	p->py = pos->y + 0.5;
	if (pos->direction == 'N')
		set_dir_north(p);
	else if (pos->direction == 'S')
		set_dir_south(p);
	else if (pos->direction == 'E')
		set_dir_east(p);
	else
		set_dir_west(p);
}