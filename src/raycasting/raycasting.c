/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:00:00 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/25 12:00:00 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_mlx(t_scene *scene)
{
	scene->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", true);
	if (!scene->mlx)
		error_exit("Failed to initialize MLX", scene);
	scene->img = mlx_new_image(scene->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!scene->img)
		error_exit("Failed to create image", scene);
	mlx_image_to_window(scene->mlx, scene->img, 0, 0);
}

void	load_textures(t_scene *scene)
{
	if (scene->texture.north.path)
		scene->texture.north.wall = mlx_load_png(scene->texture.north.path);
	if (scene->texture.south.path)
		scene->texture.south.wall = mlx_load_png(scene->texture.south.path);
	if (scene->texture.west.path)
		scene->texture.west.wall = mlx_load_png(scene->texture.west.path);
	if (scene->texture.east.path)
		scene->texture.east.wall = mlx_load_png(scene->texture.east.path);
}

void	render_frame(t_scene *scene)
{
	// Limpiar imagen
	// Dibujar suelo y techo
	for (int y = 0; y < SCREEN_HEIGHT / 2; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			mlx_put_pixel(scene->img, x, y, scene->ceiling);
			mlx_put_pixel(scene->img, x, y + SCREEN_HEIGHT / 2, scene->floor);
		}
	}
	// Raycast
	raycast(scene);
}

void	raycast(t_scene *scene)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		// Calcular dirección del rayo
		double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		double ray_dir_x = scene->player.dir_x + scene->player.plane_x * camera_x;
		double ray_dir_y = scene->player.dir_y + scene->player.plane_y * camera_x;

		// Posición en mapa
		int map_x = (int)scene->player.pos_x;
		int map_y = (int)scene->player.pos_y;

		// Longitud del rayo desde un lado a otro
		double side_dist_x;
		double side_dist_y;

		// Longitud del rayo desde un lado a otro
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		// Dirección del paso
		int step_x;
		int step_y;

		int hit = 0;
		int side;

		// Calcular step y side_dist iniciales
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (scene->player.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - scene->player.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (scene->player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - scene->player.pos_y) * delta_dist_y;
		}

		// DDA
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (scene->map[map_x][map_y] == '1')
				hit = 1;
		}

		// Calcular distancia perpendicular
		if (side == 0)
			perp_wall_dist = (map_x - scene->player.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - scene->player.pos_y + (1 - step_y) / 2) / ray_dir_y;

		// Calcular altura de línea
		int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);

		// Calcular píxeles más bajos y altos
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;

		// Elegir color de pared
		int color;
		if (side == 0)
			color = 0xFF0000FF; // Azul para X
		else
			color = 0xFFFF0000; // Rojo para Y

		// Dibujar línea vertical
		for (int y = draw_start; y < draw_end; y++)
		{
			mlx_put_pixel(scene->img, x, y, color);
		}
	}
}