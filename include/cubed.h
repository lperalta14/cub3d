/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/17 18:32:39 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../my_lib/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

typedef enum e_error
{
	MLX,
	FILE,
	INIT,
}	t_error;

typedef enum type
{
	NO,
	SO,
	WE,
	EA,
}	type_t;

typedef struct texture
{
	char *rute;
	
	
	
} t_texture;



typedef struct wall
{
	t_texture	*NO;
	t_texture	*SO;
	t_texture	*WE;
	t_texture	*EA;
}	t_texture;

typedef struct color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct scene
{
	char **map;
	t_texture texture;
	t_color floor;
	t_color ceiling;
}	t_scene;

int	check_file(char *argv);
t_scene	init(char *filename); //por hacer
void destroy(t_scene *data); //por hacer

/* Map validation functions */
int	valid_char_in_map(char c);
int	valid_map(t_scene *data);
int	check_map_closed(t_scene *data);
int	count_player_pos(t_scene *data);

#endif