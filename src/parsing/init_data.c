/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:21:35 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/24 20:03:46 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"#include "../../src/raycasting/raycasting.h"#include <fcntl.h>

static int	read_line_and_parse(t_scene *data, char *line)
{
	int  	i;
	
	i = 0;
	if(!line[i])
		return(TRUE);
	if(!ft_strncmp("NO", line + i, 2))
		return(in_data_texture(line + i + 2, &data->texture.north));
	if(!ft_strncmp("SO", line + i, 2))
		return(in_data_texture(line + i + 2, &data->texture.south));
	if(!ft_strncmp("WE", line + i, 2))
		return(in_data_texture(line + 2 + i, &data->texture.west));
	if(!ft_strncmp("EA", line + i, 2))
		return(in_data_texture(line + 2 + i, &data->texture.east));
	if(!ft_strncmp("F", line + i, 1))
		return(in_colors(line + 2 + i, &data->floor));	
	if(!ft_strncmp("C", line + i, 1))
		return(in_colors(line + 2 + i, &data->ceiling));
	/*else
		return(check_map_closed(data));//no sé si esto iría así*/
	return(TRUE);
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

static char	*clean_line(char *line)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	while(line[i] && ft_isspace(line[i]))
		i++;
	while(line[i])
		line[j++] = line[i++];
	len = ft_strlen(line);
	if(len > 0 && ft_isspace(line[len - 1]))
		line[--j] = '\0';
	else
		line[j] = '\0';
	return (line);
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
	data->floor = -1;
	data->ceiling = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line(line);
		if(read_line_and_parse(data, line) == FALSE)
		{
			free(line);
			close(fd);
			error_exit("Problem in file .cub\n", data);
		}
		free(line);
	}
	close(fd);
	if (!exist_texture(&data->texture.north) || !exist_texture(&data->texture.south)
		|| !exist_texture(&data->texture.west) || !exist_texture(&data->texture.east))
		error_exit("Missing textures\n", data);
	if (data->ceiling < 0 || data->floor < 0)
		error_exit("Missing colors\n", data);
	load_textures(data);
	/*if (!data->map)
		error_exit("No map found\n", data);*/
	return (*data);
}
