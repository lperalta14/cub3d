/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/24 18:52:13 by anzarago         ###   ########.fr       */
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

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# define TRUE 1
# define FALSE 0


typedef struct texture
{
	char			*path;
	mlx_texture_t	*wall;
} t_texture;


typedef struct direction
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
}	t_direction;


typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;


typedef struct scene
{
	char		**map;
	t_direction	texture;
	int			floor;
	int			ceiling;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	player;
}	t_scene;

int		check_file(char *argv);
t_scene	init(char *filename); //por hacer
void	destroy(t_scene *data); //por hacer
void	free_texture(t_texture *direction);

/* Map validation functions */
int		valid_char_in_map(char c);
int		valid_map(t_scene *data);
int		check_map_closed(t_scene *data);
int		count_player_pos(t_scene *data);


void	error_exit(char *msg, t_scene *data);

/* Parsing*/
int		exist_texture(t_texture *direction);
int		in_data_texture(char *line, t_texture *direction);
int		in_colors(char *line, int *paint);

/*Utls*/
int		isdigit_str(char *str);

/* Raycasting */
void	init_mlx(t_scene *scene);
void	init_player(t_scene *scene);
void	load_textures(t_scene *scene);
void	render_frame(t_scene *scene);
void	raycast(t_scene *scene);