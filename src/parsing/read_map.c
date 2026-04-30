/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:10:34 by lperalta          #+#    #+#             */
/*   Updated: 2026/04/30 21:26:05 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

/*int manage_map(char *line, t_scene *data)
{
	char *empty_line;
	if(!line || !data)
		return(FALSE); //y si llega al final?
	if(data->map_lines == 0)
	{
		empty_line = ft_strtrim(line, " \t\n");
		if(empty_line && !empty_line[0])
		{
			free(empty_line);
			return(TRUE);
		}
		free(empty_line);
	}
	data->map_lines++;
	return(TRUE);
}*/

static	int check_premap(t_scene data)
{
	int colours;
	int	texture;
	
	colours = 0;
	texture = 0;
	if(data.ceiling != -1 && data.floor != -1)
		colours = 1;
	if(exist_texture(&data.texture.east) && exist_texture(&data.texture.west) 
		&& exist_texture(&data.texture.south) && exist_texture(&data.texture.north))
		texture = 1;
	if(texture && colours)
		return(TRUE);
	else
		return(FALSE);
}

int create_map(int fd, t_scene *data)
{
	char	*line;
	int		seq;
	int		flag;

	if(check_premap(*data) == FALSE)
		return(FALSE);
	seq = 0;
	flag = 0;
	data->map = malloc(sizeof(char *) * (data->map_lines + 1));
	if(!data->map)
		return(FALSE);
	while(seq < data->map_lines)
	{
		line = get_next_line(fd);
		if(line && (line[0] == '1' || seq != 0))
		{
			data->map[seq] = ft_strtrim(line, "\n");
			if(!data->map[seq])
				flag = 1;
			seq++;
		}
		free(line);
	}
	data->map[seq] = NULL;
	if(flag == 1)
		return(FALSE);
	if(check_map(data) == TRUE)
		return(TRUE);
	return(FALSE);
}
