/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_isspaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:17:26 by anzarago          #+#    #+#             */
/*   Updated: 2026/04/30 19:51:53 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

char	*clean_line(char *line)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while(line[i] && ft_isspace(line[i]))
		i++;
	while(line[i])
		line[j++] = line[i++];
	len = ft_strlen(line);
	if(len > 0 && ft_isspace(line[len - 1]))
		line[--j] = '\0';
	else
		line[j] = '\0';
	return (line);
}
