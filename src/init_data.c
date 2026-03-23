/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:21:35 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/23 18:25:46 by anzarago         ###   ########.fr       */
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

static int	in_data_texture(char *line, t_texture *direction)
{
	char *clean_path;
	
	if(direction->path || direction->wall)
		return(FALSE);
	clean_path = ft_strtrim(line, " \t\n");
	if(!clean_path)
		return(FALSE);
	direction->path = clean_path;
	direction->wall = mlx_load_png(clean_path);
	if(!direction->wall)
	{
		free(direction->path);
		direction->path = NULL;
		return(FALSE);
	}
	return(TRUE);
}

static int	read_line_and_parse(/*int fd,*/ t_scene *data, char *line)
{
	int  	i;
	
	i = 0;
	if (!line)
		return(TRUE);
	if(line[i] && ft_isspace(line[i]))
		i++;
	if(!line[i])
		return(TRUE);
	if(!ft_strncmp("NO", line, 2))
		return(in_data_texture(line, &data->texture.north));
	if(!ft_strncmp("SO", line, 2))
		return(in_data_texture(line, &data->texture.south));
	if(!ft_strncmp("WE", line, 2))
		return(in_data_texture(line, &data->texture.west));
	if(!ft_strncmp("EA", line, 2))
		return(in_data_texture(line, &data->texture.east));
	else
		return(check_map_closed(data));//no sé si esto iría así
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
		line = get_next_line(fd);
		if (!line)
			break ;
		if(read_line_and_parse(/*fd,*/ data, line)== FALSE)
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
	//if (colors)
		//error_exit("Missing colors\n", data);
	if (!data->map)
		error_exit("No map found\n", data);
	return (*data);
}
