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


