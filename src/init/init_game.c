
#include "../../include/cubed.h"


static void	on_close(void *param)
{
	t_game	*game;
 
	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

static void	load_one(t_game *game, t_texture *tex, char *label)
{
	tex->wall = mlx_load_png(tex->path);
	if (!tex->wall)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(label, 2);
		ft_putstr_fd("\n", 2);
		mlx_terminate(game->mlx);
		destroy(game->scene);
		exit(1);
	}
}
 
static void	load_textures(t_game *game)
{
	load_one(game, &game->scene->texture.n, "NO");
	load_one(game, &game->scene->texture.s, "SO");
	load_one(game, &game->scene->texture.w, "WE");
	load_one(game, &game->scene->texture.e, "EA");
}

int	init_game(t_game *game, t_scene *scene)
{
	game->scene = scene;
	game->mlx = mlx_init(WIN_W, WIN_H, "cub3D", true);
	if (!game->mlx)
		return (0);
	game->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		return (0);
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
	{
		mlx_terminate(game->mlx);
		return (0);
	}
	mlx_close_hook(game->mlx, on_close, game);
	load_textures(game);
	init_player(game);
	return (1);
}
