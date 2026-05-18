/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:47:53 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/12 19:48:12 by lperalta         ###   ########.fr       */
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

static void	move(t_game *game, double dx, double dy)
{
	char	**map;

	map = game->scene->map;
	if (map[(int)game->player.py][(int)(game->player.px + dx)] != '1')
		game->player.px += dx;
	if (map[(int)(game->player.py + dy)][(int)game->player.px] != '1')
		game->player.py += dy;
}

static void	handle_move(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, p->dx * MOV_SPEED, p->dy * MOV_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, -p->dx * MOV_SPEED, -p->dy * MOV_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, p->dy * MOV_SPEED, -p->dx * MOV_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -p->dy * MOV_SPEED, p->dx * MOV_SPEED);
}

void	handle_input(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	handle_move(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(&game->player, -ROT_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(&game->player, +ROT_SPEED);
	handle_mouse(game);
}
