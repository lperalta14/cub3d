/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/17 19:35:19 by anzarago         ###   ########.fr       */
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

typedef struct color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct scene
{
	char		**map;
	t_direction	texture;
	t_color		floor;
	t_color		ceiling;
}	t_scene;

int	check_file(char *argv);
t_scene	init(char *filename); //por hacer
void destroy(t_scene *data); //por hacer
void free_texture(t_texture *direction);

/* Map validation functions */
int	valid_char_in_map(char c);
int	valid_map(t_scene *data);
int	check_map_closed(t_scene *data);
int	count_player_pos(t_scene *data);

#endif