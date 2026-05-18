/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:41:41 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/11 20:50:29 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	exist_text(t_texture *direction)
{
	if (!direction)
		return (FALSE);
	if (!direction->path)
		return (FALSE);
	return (TRUE);
}

int	in_data_texture(char *line, t_texture *direction)
{
	char	*clean_path;

	if (exist_text(direction))
		return (FALSE);
	clean_path = ft_strtrim(line, " \t\n");
	if (!clean_path)
		return (FALSE);
	direction->path = clean_path;
	direction->wall = NULL;
	return (TRUE);
}
