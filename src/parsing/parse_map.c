/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:01:58 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/21 18:28:38 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int check_map(t_scene *data)
{
	int	i;
	int x;
	int y;

	if (!data || !data->map)
		return (FALSE);
	i = -1;
	if(!valid_map(data))
		return (FALSE);// verificar que todas las lineas solo tengan caracteres validos y solo haya una N
	get_player_pos(data);//Obtener la posicion de N en su x e y; Guardar en algo como data.player.pos (que tiene su x e y)
	flood_fill(data->map, data.player.pos.x, data.player.pos.y, &data.valid);
	if (data.valid == FALSE) //El mapa no esta cerrado desde la posicion del jugador
		return (FALSE)
	if (!verify_map_zero(data.map)) //Si el mapa sigue teniendo zeros, el mapa es invalido
		return (FALSE);
	return (TRUE);
}

void flood_fill(char **grid, int x, int y, bool *valid)
{
	int	cols;

	if (y < 0 || x < 0)
		return ;
	cols = ft_strlen(data->map[line]);
	if (y >= data->map_lines || x >= cols)
	{
		data.valid = FALSE;
		return ;
	}
	if (data->map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->found_c += 1;
	if (map[y][x] == 'E')
		game->found_e += 1;
	map[y][x] = 'V';
	ft_floodfill(++line, y + 1, x, game);
	ft_floodfill(++line, y - 1, x, game);
	ft_floodfill(++line, y, x + 1, game);
	ft_floodfill(++line, y, x - 1, game);
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