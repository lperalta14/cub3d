/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/17 15:42:55 by anzarago         ###   ########.fr       */
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
	t_texture texture;
	t_color floor;
	t_color ceiling;
	int		fd;
}	t_scene;

int	check_file(char *argv);
int init_data(t_scene *data, char *file);
void clean_data(t_scene *data); //por hacer

#endif