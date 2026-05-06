/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 00:00:00 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/06 20:34:34 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static char	**build_map(void)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * 6);
	if (!map)
		return (NULL);
	map[0] = ft_strdup("11111111111111111111111111111111111111");
	map[1] = ft_strdup("11111100000000000000000000000000000111");
	map[2] = ft_strdup("11100000000000000000000000000000111111");
	map[3] = ft_strdup("11111111111S11111111111111111111111111");
	map[4] = ft_strdup("11111111111111111111111111111111111111");
	map[5] = NULL;
	i = 0;
	while (i < 5)
	{
		if (!map[i])
		{
			ft_freematrix(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

t_scene	init(char *filename)
{
	t_scene	data;

	(void)filename;
	ft_bzero(&data, sizeof(t_scene));
	data.map = build_map();
	//if (!data.map)
	//{
	//	data.valid = false;
	//	return (data);
	//}
	data.map_lines = 5;
	data.texture.north.path = ft_strdup("./texture/north_pkm.png");
	data.texture.south.path = ft_strdup("./texture/south_pkm.png");
	data.texture.west.path = ft_strdup("./texture/west_pkm.png");
	data.texture.east.path = ft_strdup("./texture/east_pkm.png");
	data.floor = (123 << 16) | (174 << 8) | 123;
	data.ceiling = (167 << 16) | (214 << 8) | 255;
	data.play_post.x = 11;
	data.play_post.y = 3;
	data.play_post.direction = 'S';
	//data.valid = true;
	return (data);
}
