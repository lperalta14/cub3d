/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 20:26:17 by lperalta         ###   ########.fr       */
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
	char **map;
	t_texture texture;
	t_color floor;
	t_color ceiling;
}	t_scene;

int	check_file(char *argv);
t_scene init(char *argv); //por hacer
void destroy(t_scene *data); //por hacer

#endif