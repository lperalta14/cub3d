/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:44:55 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/17 20:05:02 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void free_texture(t_texture *direction)
{
	if(!direction)
		return ;
	if(direction->path)
	{
		free(direction->path);
		direction->path = NULL;
	}
	if( direction->wall)
	{
		mlx_delete_texture(direction->wall);
		direction->wall = NULL;
	}
}

void	destroy(t_scene *data)
{
	if (!data)
		return ;
	free_texture(&data->texture.north);
	free_texture(&data->texture.south);
	free_texture(&data->texture.west);
	free_texture(&data->texture.east); //comprueba dentro si existe, asi nos ahorramos los ifs
	if (data->map)
	{
		ft_freematrix(data->map);
		/*i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);*/
	}
	free(data);
}
