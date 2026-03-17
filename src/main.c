/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:51:20 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/16 by lperalta                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_scene	data;

	if (argc != 2)
		return (ft_printf("1"));
	data = init(argv[1]);
	//if (!data.map)
		//return (ft_printf("1"));
	destroy(&data);
	return (0);
}
