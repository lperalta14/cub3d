/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:21:35 by lperalta          #+#    #+#             */
/*   Updated: 2026/03/16 by lperalta                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	valid_char_in_map(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' 
		|| c == ' ' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	valid_map(t_scene *data)
{
	int	i;
	int	j;

	if (!data || !data->map)
		return (FALSE);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (valid_char_in_map(data->map[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	count_player_pos(t_scene *data)
{
	int	i;
	int	j;
	int	count;

	if (!data || !data->map)
		return (0);
	count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' 
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*static int	is_map_border_cell(t_scene *data, int row, int col)
{
	if (!data || !data->map || !data->map[row])
		return (FALSE);
	if (data->map[row][col] == ' ')
		return (FALSE);
	if (data->map[row][col] != '1')
		return (FALSE);
	return (TRUE);
}*/

int	check_map_closed(t_scene *data)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	if (!data || !data->map)
		return (FALSE);
	rows = 0;
	while (data->map[rows])
		rows++;
	if (rows == 0)
		return (FALSE);
	i = 0;
	while (data->map[i])
	{
		cols = ft_strlen(data->map[i]);
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
		i++;
	}
	return (TRUE);
}
