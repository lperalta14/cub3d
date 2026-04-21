/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:10:34 by lperalta          #+#    #+#             */
/*   Updated: 2026/04/20 19:47:48 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int manage_map(char *line, t_scene *data)
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
	printf("manage maps\n");
	data->map_lines++;
	return(TRUE);
}

int create_map(int fd, t_scene *data)
{
	char	*line;
	int		seq;
	int		flag;

	seq = 0;
	flag = 0;
	printf("create maps 0\n");
	data->map = malloc(sizeof(char**) * data->map_lines + 1);
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
		printf("create maps\n");
	}
	data->map[seq] = NULL;
	if(flag == 1)
		return(FALSE);
	if(valid_map(data) == TRUE && check_map_closed(data) == TRUE)
		return(TRUE);
	return(FALSE);
}
//a revisar errores de primera entrada