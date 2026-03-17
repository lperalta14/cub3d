/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:34:47 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/16 19:51:00 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char *line_type(int fd, type_t type)
{
	
}

int init_data(t_scene *data, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		close(fd);
		return(FALSE); //no se pondria un msj especifico, vamos a ir viendo esto
	}
	
}