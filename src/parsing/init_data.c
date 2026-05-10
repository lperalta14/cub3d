/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:34:07 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/08 16:56:17 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

static void	count_player_pos(t_scene *data)
{
	int	i;
	int	j;
	int count;

	count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->play_post.direction = data->map[i][j];
				data->play_post.x = j;
				data->play_post.y = i;
				count ++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		error_exit("Player problem", data);
}

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
		ft_replacechar(line, '\n', '\0');
		clean_line(line);
		if(read_line_and_parse(&data, line) == FALSE)
			flag = 1;
		free(line);
	}
	close(fd);
	data = extr_information(data, filename, flag);
	count_player_pos(&data);
	return (data);
}

