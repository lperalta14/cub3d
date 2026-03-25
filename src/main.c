/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:51:20 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/16 by lperalta                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include "../src/raycasting/raycasting.h"
#include <fcntl.h>

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene *scene = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(scene->mlx);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (scene->map[(int)(scene->player.pos_x + scene->player.dir_x * 0.1)][(int)scene->player.pos_y] != '1')
			scene->player.pos_x += scene->player.dir_x * 0.1;
		if (scene->map[(int)scene->player.pos_x][(int)(scene->player.pos_y + scene->player.dir_y * 0.1)] != '1')
			scene->player.pos_y += scene->player.dir_y * 0.1;
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (scene->map[(int)(scene->player.pos_x - scene->player.dir_x * 0.1)][(int)scene->player.pos_y] != '1')
			scene->player.pos_x -= scene->player.dir_x * 0.1;
		if (scene->map[(int)scene->player.pos_x][(int)(scene->player.pos_y - scene->player.dir_y * 0.1)] != '1')
			scene->player.pos_y -= scene->player.dir_y * 0.1;
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		double old_dir_x = scene->player.dir_x;
		scene->player.dir_x = scene->player.dir_x * cos(-0.1) - scene->player.dir_y * sin(-0.1);
		scene->player.dir_y = old_dir_x * sin(-0.1) + scene->player.dir_y * cos(-0.1);
		double old_plane_x = scene->player.plane_x;
		scene->player.plane_x = scene->player.plane_x * cos(-0.1) - scene->player.plane_y * sin(-0.1);
		scene->player.plane_y = old_plane_x * sin(-0.1) + scene->player.plane_y * cos(-0.1);
	}
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		double old_dir_x = scene->player.dir_x;
		scene->player.dir_x = scene->player.dir_x * cos(0.1) - scene->player.dir_y * sin(0.1);
		scene->player.dir_y = old_dir_x * sin(0.1) + scene->player.dir_y * cos(0.1);
		double old_plane_x = scene->player.plane_x;
		scene->player.plane_x = scene->player.plane_x * cos(0.1) - scene->player.plane_y * sin(0.1);
		scene->player.plane_y = old_plane_x * sin(0.1) + scene->player.plane_y * cos(0.1);
	}
}

int	main(int argc, char **argv)
{
	t_scene	data;

	if (argc != 2)
		return (ft_printf("Usage: ./cub3d <map.cub>\n"));
	data = init(argv[1]);
	init_mlx(&data);
	init_player(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, (void (*)(void *))render_frame, &data);
	mlx_loop(data.mlx);
	destroy(&data);
	return (0);
}
