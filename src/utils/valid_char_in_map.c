/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:18:42 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/11 21:19:41 by anzarago         ###   ########.fr       */
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
