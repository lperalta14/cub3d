/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:42:15 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/05 20:34:44 by anzarago         ###   ########.fr       */
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

typedef struct scene
{
	char		**map;
	int			map_lines;
	t_direction	texture;
	int			floor;
	int			ceiling;
}	t_scene;

//PARSING
int		check_file(char *argv);
int		in_colors(char *line, int *paint);
t_scene	init(char *filename);
int		create_map(int fd, t_scene *data);
int		manage_map(char *line, t_scene *data);
int		check_map(t_scene *data);
int		exist_texture(t_texture *direction);
int		in_data_texture(char *line, t_texture *direction);
int		read_line_and_parse(t_scene *data, char *line);
t_scene	extr_information(t_scene data, char *filename, int flag);

//UTILS
void	error_exit(char *msg, t_scene *data);
void	free_texture(t_texture *direction);
void	destroy(t_scene *data);
int		isdigit_str(char *str);
int		valid_char_in_map(char c);
int		valid_map(t_scene *data);
//void	count_player_pos(t_scene *data);
int		check_map_closed(char **c_map);
char 	**clone_map(char **map);
char	*clean_line(char *line);
void	ft_freematrix_i(char **str, int ind);


#endif