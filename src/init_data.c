/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:21:35 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/17 12:56:13 by lperalta         ###   ########.fr       */
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

void	destroy(t_scene *data)
{
	int	i;

	if (!data)
		return ;
	if (data->texture.north)
		free(data->texture.north);
	if (data->texture.south)
		free(data->texture.south);
	if (data->texture.west)
		free(data->texture.west);
	if (data->texture.east)
		free(data->texture.east);
	if (data->map)
	{
		ft_freematrix(data->map);
		/*i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);*/
	}
	free(data);
}

static void	read_line_and_parse(int fd, t_scene *data, char *line)
{
	(void)data;
	(void)line;
	(void)fd;
	line = get_next_line(fd);
}

t_scene	init(char *filename)
{
	t_scene	*data;
	int		fd;
	char	*line;

	if (!filename)
		error_exit("Filename is NULL\n", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file\n", data);
	data = (t_scene *)malloc(sizeof(t_scene));
	if (!data)
		error_exit("Memory allocation failed\n", data);
	data->texture.north = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.east = NULL;
	data->map = NULL;//sacar en una función de init_data_valor
	while (1)
	{
		line = NULL;
		read_line_and_parse(fd, data, line); //función de leer bucle y guardar los datos
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	if (!data->texture.north || !data->texture.south 
		|| !data->texture.west || !data->texture.east)
		error_exit("Missing textures\n", data);
	if (!data->map)
		error_exit("No map found\n", data);
	return (*data);
}
