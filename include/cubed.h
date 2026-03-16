/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 19:44:42 by lperalta         ###   ########.fr       */
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

typedef struct texture
{
	char *north;
	char *south;
	char *west;
	char *east;
}	t_texture;

typedef struct color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct scene
{
	t_texture texture;
	t_color floor;
	t_color ceiling;
	char **map;
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