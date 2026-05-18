/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:11:41 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/11 21:16:48 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	find_long_map(char **map)
{
	int	i;
	int	j;
	int	len_max;

	i = 0;
	len_max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len_max)
			len_max = j;
		i++;
	}
	return (len_max);
}

char	*map_filled(char *map, int long_max)
{
	char	*r_map;
	int		i;

	i = 0;
	r_map = malloc(sizeof(char) * (long_max + 1));
	if (!r_map)
		return (NULL);
	while (map[i])
	{
		r_map[i] = map[i];
		i++;
	}
	while (i < long_max)
	{
		r_map[i] = ' ';
		i++;
	}
	r_map[i] = '\0';
	return (r_map);
}

char	**clone_map(char **map)
{
	int		rows_nbr;
	char	**map_copy;
	int		i;
	int		long_max;

	i = 0;
	if (!map)
		return (NULL);
	rows_nbr = height_map(map);
	long_max = find_long_map(map);
	map_copy = malloc(sizeof(char *) * (rows_nbr + 1));
	if (!map_copy)
		return (NULL);
	while (i < rows_nbr)
	{
		map_copy[i] = map_filled(map[i], long_max);
		if (!map_copy[i])
		{
			ft_freematrix_i(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
