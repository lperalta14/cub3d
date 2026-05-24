/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:50:01 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/18 17:52:19 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static mlx_texture_t	*get_texture(t_game *game, t_ray *ray)
{
	t_direction	*tex;

	tex = &game->scene->texture;
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (tex->e.wall);
		return (tex->w.wall);
	}
	if (ray->step_y > 0)
		return (tex->s.wall);
	return (tex->n.wall);
}

static void	calc_tex_x(t_ray *ray, mlx_texture_t *tex)
{
	ray->tex_x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->step_x < 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->step_y > 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	ray->tex_step = (double)tex->height / ray->line_h;
	ray->tex_pos = (ray->draw_start - WIN_H / 2
			+ ray->line_h / 2) * ray->tex_step;
}

static uint32_t	get_tex_color(mlx_texture_t *tex, int tex_x, double tex_pos)
{
	int			tex_y;
	uint8_t		*pixel;

	tex_y = (int)tex_pos % tex->height;
	pixel = tex->pixels + (tex_y * tex->width + tex_x) * 4;
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	mlx_texture_t	*tex;
	int				y;
	uint32_t		color;

	tex = get_texture(game, ray);
	calc_tex_x(ray, tex);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		color = get_tex_color(tex, ray->tex_x, ray->tex_pos);
		mlx_put_pixel(game->img, x, y, color);
		ray->tex_pos += ray->tex_step;
		y++;
	}
}
