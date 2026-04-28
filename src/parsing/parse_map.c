/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:01:58 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/28 21:07:14 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

/*static int	verify_map_zero(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '0')
				return(FALSE);
			i++;
		}
		i++;
	}
	return(TRUE);
}*/

/*void	flood_fill(char **map, int x, int y, t_scene *data)
{
	int	cols;

	if (y < 0 || x < 0)
		return ;
	cols = ft_strlen(map[]);
	if (y >= data->map_lines || x >= cols)
	{
		data->valid = FALSE;
		return ;
	}
	if (data->map[y][x] == '1')
		return ;
	if (data->map[y][x] == 'N')
		return ;
	data->map[y][x] = 'V';
	flood_fill(++line, y + 1, x, data);
	flood_fill(++line, y - 1, x, data);
	flood_fill(++line, y, x + 1, data);
	flood_fill(++line, y, x - 1, data);
}*/

/*void	count_player_pos(t_scene *data)
{
	int	i;
	int	j;
	int	find;

	find = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' 
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W') //crear funcion para reducir
			{
				data->play_post.direction = data->map[i][j];
				find++;
			}
			j++;
		}
		i++;
	}
	if(find == 1)
	{
		data->play_post.x = j;
		data->play_post.y = i;
	}
}*/

int	check_map_closed(char **c_map)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	rows = 0;
	while (c_map[rows])
		rows++;
	if (rows == 0)
		return (FALSE);
	i = 0;
	while (c_map[i])
	{
		cols = ft_strlen(c_map[i]);
		j = 0;
		while (j < cols)
		{
			if (c_map[i][j] != '1' && c_map[i][j] != ' ' 
				&& c_map[i][j] != '\n')
			{
				if (i == 0 || i == rows - 1)
					return (FALSE);
				if (j == 0 || j == cols - 1)
					return (FALSE);
				if (c_map[i - 1][j] == ' ' || c_map[i + 1][j] == ' '
					|| c_map[i][j - 1] == ' ' || c_map[i][j + 1] == ' ')
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	printf("entra 122\n");
	return (TRUE);
}

int check_map(t_scene *data)
{
	char **c_map;
	
	if (!data || !data->map)
		return (FALSE);
	if(!valid_map(data))
		return (FALSE);// verificar que todas las lineas solo tengan caracteres validos y solo haya una N
	/*get_player_pos(data);
	if(data->play_post.x < 0 || data->play_post.y < 0)
		return(FALSE);*/
	c_map = clone_map(data->map);
	if(!c_map)
		return(FALSE);
	if(check_map_closed(c_map) == FALSE)
	{
		ft_freematrix(c_map);
		return(FALSE);
	}
	printf("TODO PIOLA\n");
	ft_freematrix(c_map);
	return (TRUE);
}
