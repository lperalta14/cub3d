/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:46:04 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/11 18:01:04 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

static int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	parse_colors(int primarycolor)
{
	if (primarycolor < 0 || primarycolor > 255)
		return (-1);
	return (primarycolor);
}

int	in_colors(char *line, int *paint)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (!line || !paint || *paint != -1)
		return (FALSE);
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	rgb = ft_split(line, ',');
	if (!rgb)
		return (FALSE);
	if ((!rgb[0] || !rgb[1] || !rgb[2] || rgb[3] || !isdigit_str(rgb[0])
			|| !isdigit_str(rgb[1]) || !isdigit_str(rgb[2])))
	{
		ft_freematrix(rgb);
		return (FALSE);
	}
	r = parse_colors(ft_atoi(rgb[0]));
	g = parse_colors(ft_atoi(rgb[1]));
	b = parse_colors(ft_atoi(rgb[2]));
	*paint = get_rgb(r, g, b);
	ft_freematrix(rgb);
	return (TRUE);
}
