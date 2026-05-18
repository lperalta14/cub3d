/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:42:59 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/14 15:56:35 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed_bonus.h"

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
