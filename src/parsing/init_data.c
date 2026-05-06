/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:34:07 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/06 19:30:53 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"


static t_scene prep_init(t_scene data)
{
	data.texture.north.path = NULL;
	data.texture.north.wall = NULL;
	data.texture.south.path = NULL;
	data.texture.south.wall = NULL;
	data.texture.west.path = NULL;
	data.texture.west.wall = NULL;
	data.texture.east.path = NULL;
	data.texture.east.wall = NULL;
	data.map = NULL;
	data.floor = -1;
	data.ceiling = -1;
	data.map_lines = 0;
	return (data);	
}
static int	openfile( char *filename)
{
	int fd;
	
	if (!filename)
		error_exit("File is NULL\n", NULL);
	fd = open(filename, O_RDONLY);
	if(check_file(filename) == FALSE)
		error_exit("File is grown", NULL);
	if (fd < 0)
		error_exit("Cannot open file\n", NULL);
	return(fd);
}

t_scene	init(char *filename)
{
	t_scene	data;
	int		fd;
	char	*line;
	int		flag;
	
	flag = 0;
	fd = openfile(filename);
	ft_bzero(&data, (sizeof(t_scene) * 1));
	data = prep_init(data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line(line);
		if(read_line_and_parse(&data, line) == FALSE)
			flag = 1;
		free(line);
	}
	close(fd);
	data = extr_information(data, filename, flag);
	return (data);
}

