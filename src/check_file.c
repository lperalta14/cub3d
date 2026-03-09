/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:57:05 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/09 20:15:13 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "libft.h"

int	check_file(char *argv)
{
	char *type;

	if(ft_strlen(argv) < 5)
		return(FALSE);
	type = ft_strrchr(argv, '.');
	if(!type || type == argv || strlen(type) != 4)
		return(FALSE);
	if(ft_strncmp(type, ".cub", 5) == 0)
		return(TRUE);
	return(FALSE);
}
