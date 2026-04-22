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
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_game	game;
 
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cubed map.cub\n", 2);
		return (1);
	}
	scene = init(argv[1]);
	if (!scene.valid)
		return (1);
	if (!init_game(&game, &scene))
	{
		destroy(&scene);
		return (1);
	}
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	destroy(&scene);
	return (0);
}
