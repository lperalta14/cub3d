/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:42:15 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/22 00:00:00 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../my_lib/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define WIN_W 1280
# define WIN_H 720
# define MOV_SPEED 0.05
# define ROT_SPEED 0.03

typedef struct s_texture
{
	char			*path;
	mlx_texture_t	*wall;
}	t_texture;

typedef struct s_direction
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
}	t_direction;

typedef struct s_position
{
	int		x;
	int		y;
	char	direction;
}	t_position;

typedef struct s_scene
{
	char		**map;
	int			map_lines;
	t_direction	texture;
	int			floor;
	int			ceiling;
	t_position	play_post;
	bool		valid;
}	t_scene;

typedef struct s_player
{
	double	px;
	double	py;
	double	dx;
	double	dy;
	double	cx;
	double	cy;
}	t_player;

typedef struct s_ray
{
	double	cam_x;
	double	rdx;
	double	rdy;
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	double	wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	wall_x;
	double	tex_step;
	double	tex_pos;
}	t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_scene		*scene;
	t_player	player;
}	t_game;

//PARSING
int		check_file(char *argv);
int		in_colors(char *line, int *paint);
t_scene	init(char *filename);
int		create_map(int fd, t_scene *data);
int		manage_map(char *line, t_scene *data);
void	flood_fill(char **map, int x, int y, t_scene *data);
int		check_map(t_scene *data);
int		exist_texture(t_texture *direction);
int		in_data_texture(char *line, t_texture *direction);

//UTILS
void	error_exit(char *msg, t_scene *data);
void	free_texture(t_texture *direction);
void	destroy(t_scene *data);
int		isdigit_str(char *str);
int		valid_char_in_map(char c);
int		valid_map(t_scene *data);
void	count_player_pos(t_scene *data);
char	**clone_map(char **map);

//INIT
void	init_player(t_game *game);
int		init_game(t_game *game, t_scene *scene);
void	load_textures(t_game *game);

//RENDER
void	render_frame(void *param);
void	cast_ray(t_game *game, t_ray *ray, int x);
void	draw_column(t_game *game, t_ray *ray, int x);
void	draw_floor_ceiling(t_game *game);

//INPUT
void	handle_input(t_game *game);

#endif
