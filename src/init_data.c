/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:21:35 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/17 20:00:24 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include <fcntl.h>

static void	error_exit(char *msg, t_scene *data)
{
	destroy(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}


static void	read_line_and_parse(int fd, t_scene *data, char *line)
{
	(void)data;
	(void)line;
	(void)fd;
	line = get_next_line(fd);
	
}
static t_scene *init_texture(t_scene *data)
{
	data->texture.north.path = NULL;
	data->texture.north.wall = NULL;
	data->texture.south.path = NULL;
	data->texture.south.wall = NULL;
	data->texture.west.path = NULL;
	data->texture.west.wall = NULL;
	data->texture.east.path = NULL;
	data->texture.east.wall = NULL;

	return (data);	
}


int	exist_texture(t_texture *direction)
{
	if (!direction)
		return (FALSE);
	if (!direction->path || !direction->wall)
		return (FALSE);
	return (TRUE);
}

t_scene	init(char *filename)
{
	t_scene	*data;
	int		fd;
	char	*line;
		
	if (!filename)
		error_exit("Filename is NULL\n", NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || check_file(filename) == FALSE)
		error_exit("Cannot open file\n", NULL);
	data = (t_scene *)malloc(sizeof(t_scene));
	if (!data)
		error_exit("Memory allocation failed\n", NULL);
	data = init_texture(data);
	data->map = NULL;
	while (1)
	{
		line = NULL;
		read_line_and_parse(fd, data, line);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	if (!exist_texture(&data->texture.north) || !exist_texture(&data->texture.south)
		|| !exist_texture(&data->texture.west) || !exist_texture(&data->texture.east))
		error_exit("Missing textures\n", data);
	//if (colors)
		//error_exit("Missing colors\n", data);
	if (!data->map)
		error_exit("No map found\n", data);
	return (*data);
}
