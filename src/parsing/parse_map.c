/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:01:58 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/21 21:11:37 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

static int	verify_map_zero(char **map)
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
}


void	flood_fill(char **map, int x, int y, t_scene *data)
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
}

int check_map(t_scene *data)
{
	int x;
	int y;
	char **c_map;

	if (!data || !data->map)
		return (FALSE);
	if(!valid_map(data))
		return (FALSE);// verificar que todas las lineas solo tengan caracteres validos y solo haya una N
	get_player_pos(data);
	if(data->play_post.x < 0 || data->play_post.y < 0)
		return(FALSE);
	c_map = clone_map(data->map);
	if(!c_map)
		return(FALSE);
	flood_fill(c_map, data->play_post.x, data->play_post.y, &data->valid);
	if (!verify_map_zero(c_map))
	{
		ft_freematrix(c_map);
		return (FALSE);
	} //Si el mapa sigue teniendo zeros, el mapa es invalido
	ft_freematrix(c_map);
	if (data->valid == FALSE) //El mapa no esta cerrado desde la posicion del jugador
		return (FALSE);
	return (TRUE);
}

/* int	check_map_closed(t_scene *data)
{
	int	i;
	int	j;
	int	rows;
	int	cols;
	int	prev_cols;


	rows = 0;
	while (data->map[rows])
		rows++;
	if (rows == 0)
		return (FALSE);
	i = 0;
	while (data->map[i])
	{
		cols = ft_strlen(data->map[i]);
		printf("cols: %d | prev_cols: %d\n", cols, prev_cols);
		if (i && cols < prev_cols - 1)
			return (FALSE);
		j = 0;
		while (j < cols)
		{
			if (data->map[i][j] != '1' && data->map[i][j] != ' ' 
				&& data->map[i][j] != '\n')
			{
				if (i == 0 || i == rows - 1)
					return (FALSE);
				if (j == 0 || j == cols - 1)
					return (FALSE);
				if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' '
					|| data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
					return (FALSE);
			}
			j++;
		}
		prev_cols = cols;
		i++;
	}
	return (TRUE);
} */