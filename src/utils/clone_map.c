/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:11:41 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/21 21:22:48 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static int	long_map(char **map)
{
	int i;
	
	i = 0;
	while(map[i] && map)
		i++;
	return(i);
}

char **clone_map(char **map)
{
	int rows;
	char **map_copy;
	int i;
	
	i = 0;
	if(!map || !*map)
		return(NULL);
	rows = long_map(map);
	map_copy = malloc(sizeof(char *) * rows + 1);
	if(!map_copy)
		return(NULL);
	while(i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if(!map_copy[i])
		{
			ft_freematrix(map_copy);
			return(NULL);
		}
		i++;
	}
	map_copy[i] == NULL;
	return(map_copy);
}
