/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:50:40 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/12 19:51:08 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	draw_half(t_game *game, uint32_t color, int y_start, int y_end)
{
	int	x;
	int	y;

	y = y_start;
	while (y < y_end)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor_ceiling(t_game *game)
{
	draw_half(game, int_to_rgba(game->scene->ceiling), 0, WIN_H / 2);
	draw_half(game, int_to_rgba(game->scene->floor), WIN_H / 2, WIN_H);
}
