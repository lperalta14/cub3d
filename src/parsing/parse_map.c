/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:01:58 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/05 20:48:04 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int	cal_row(char **c_map)
{
	int	i;

	i = 0;
	if(!c_map || !*c_map)
		return(0);
	while(c_map[i])
		i++;
	return(i);
		
}

int	check_map_closed(char **c_map)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	rows = cal_row(c_map);
	if (rows == 0)
		return (FALSE);
	i = 0;
	cols = ft_strlen(c_map[i]);
	while (c_map[i])
	{
		j = 0;
		while (j < cols)
		{		
			if (c_map[i][j] != '1' && c_map[i][j] != ' ')
			{
				if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
					return (FALSE);
				if (c_map[i - 1][j] == ' ' || c_map[i + 1][j] == ' '
					|| c_map[i][j - 1] == ' ' || c_map[i][j + 1] == ' ')
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int check_map(t_scene *data)
{
	char **c_map;
	
	if (!data || !data->map)
		return (FALSE);
	if(!valid_map(data))
		return (FALSE);
	c_map = clone_map(data->map);
	if(!c_map)
		return(FALSE);
	if(check_map_closed(c_map) == FALSE)
	{
		ft_freematrix(c_map);
		return(FALSE);
	}
	ft_freematrix(c_map);
	return (TRUE);
	}
