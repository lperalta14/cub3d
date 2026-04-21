/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:41:41 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/21 18:39:02 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	exist_texture(t_texture *direction)
{
	if (!direction)
		return (FALSE);
	if (!direction->path || !direction->wall)
		return (FALSE);
	return (TRUE);
}

int	in_data_texture(char *line, t_texture *direction)
{
	char *clean_path;
	
	if(direction->path || direction->wall)
		return(FALSE);
	clean_path = ft_strtrim(line, " \t\n");
	if(!clean_path)
		return(FALSE);
	direction->path = clean_path;
	direction->wall = mlx_load_png(clean_path);
	if(!direction->wall)
	{
		free(direction->path);
		direction->path = NULL;
		return(FALSE);
	}
	printf("Texture loaded: %s\n", direction->path); // a borrar
	return(TRUE);
}

