
#include "../include/cubed_bonus.h"
 
int	main(int argc, char **argv)
{
	t_scene	scene;
	t_game	game;
 
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cubed_bonus map.cub\n", 2);
		return (1);
	}
	scene = init(argv[1]);
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