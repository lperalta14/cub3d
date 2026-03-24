/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:44:55 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/24 17:25:25 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	error_exit(char *msg, t_scene *data)
{
	destroy(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

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
	free_texture(&data->texture.east);
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
}
