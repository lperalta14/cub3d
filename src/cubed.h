/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/09 20:15:48 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

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
}	t_scene;

int	check_file(char *argv);
t_scene init(char *argv); //por hacer
void destroy(t_scene *data); //por hacer

#endif