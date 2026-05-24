/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:42:59 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/18 17:49:57 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed_bonus.h"

static void	rotate(t_player *p, double angle)
{
	double	old_dx;
	double	old_cx;

	old_dx = p->dx;
	old_cx = p->cx;
	p->dx = old_dx * cos(angle) - p->dy * sin(angle);
	p->dy = old_dx * sin(angle) + p->dy * cos(angle);
	p->cx = old_cx * cos(angle) - p->cy * sin(angle);
	p->cy = old_cx * sin(angle) + p->cy * cos(angle);
}

void	handle_mouse(t_game *game)
{
	int		cur_x;
	int		cur_y;
	double	delta;

	mlx_get_mouse_pos(game->mlx, &cur_x, &cur_y);
	delta = (cur_x - game->mouse_x) * ROT_SPEED * 0.1;
	if (delta != 0)
		rotate(&game->player, delta);
	game->mouse_x = cur_x;
}
