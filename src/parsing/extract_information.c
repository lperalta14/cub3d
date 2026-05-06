/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_information.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:25:49 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/06 19:34:54 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"


int	read_line_and_parse(t_scene *data, char *line)
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
	else
		return(manage_map(line, data));
	//return(TRUE);
}

t_scene	extr_information(t_scene data, char *filename, int flag)
{
	int	fd;
	
	fd = 0;
	if (!exist_texture(&data.texture.north) || !exist_texture(&data.texture.south)
		|| !exist_texture(&data.texture.west) || !exist_texture(&data.texture.east))
		error_exit("Missing textures\n", &data);
	if (data.ceiling < 0 || data.floor < 0)
		error_exit("Missing colors\n", &data);
	if(flag == 1)
		error_exit("Unexpected information or structure in .cub\n", &data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file\n", &data);
	if(!create_map(fd, &data))
	{
		close(fd);
		error_exit("Error creating map\n", &data);
	}
	if (!data.map)
	{
		close(fd);		
		error_exit("No map found\n", &data);
	}
	close(fd);
	return(data);
}
