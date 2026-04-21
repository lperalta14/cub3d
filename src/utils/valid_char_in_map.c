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

//cambiar nombre archivo

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
		printf("valid\n");
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

void	count_player_pos(t_scene *data)
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

