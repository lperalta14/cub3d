/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:10:34 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/24 20:30:40 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	manage_map(char *line, t_scene *data)
{
	char	*clean_line;

	if (!line || !data)
		return (FALSE);
	clean_line = ft_strtrim(line, " \t\n");
	if (data->map_lines == 0)
	{
		if (line && !clean_line)
			return (TRUE);
	}
	if (!exist_text(&data->texture.n) || !exist_text(&data->texture.s)
		|| !exist_text(&data->texture.w) || !exist_text(&data->texture.e))
	{
		free (clean_line);
		return (FALSE);
	}
	if (clean_line[0] != '1')
	{
		free (clean_line);
		return (FALSE);
	}
	data->map_lines++;
	free(clean_line);
	return (TRUE);
}

static int	check_premap(t_scene data)
{
	int	colours;
	int	texture;

	colours = 0;
	texture = 0;
	if (data.ceiling != -1 && data.floor != -1)
		colours = 1;
	if (exist_text(&data.texture.e) && exist_text(&data.texture.w)
		&& exist_text(&data.texture.s) && exist_text(&data.texture.n))
		texture = 1;
	if (texture != 0 && colours != 0)
		return (TRUE);
	else
		return (FALSE);
}

static char	**realloc_map(t_scene *data)
{
	if (check_premap(*data) == FALSE)
		return (NULL);
	data->map = malloc(sizeof(char *) * (data->map_lines + 1));
	if (!data->map)
		return (NULL);
	return (data->map);
}

static int	map_start(char *line)
{
	char	*clean_line;

	clean_line = ft_strtrim(line, " \t\r\f");
	if (clean_line[0] == '1')
	{
		free (clean_line);
		return (TRUE);
	}
	free (clean_line);
	return (FALSE);
}

int	create_map(int fd, t_scene *data)
{
	char	*line;
	int		seq;
	int		flag;

	seq = 0;
	flag = 0;
	data->map = realloc_map(data);
	if (!data->map)
		return (FALSE);
	while (seq < data->map_lines)
	{
		line = get_next_line(fd);
		if (line && (map_start(line) == TRUE || seq != 0))
		{
			data->map[seq] = ft_strtrim(line, "\n");
			if (!data->map[seq])
				flag = 1;
			seq++;
		}
		free (line);
	}
	data->map[seq] = NULL;
	if (flag == 0 && check_map(data) == TRUE)
		return (TRUE);
	return (FALSE);
}
