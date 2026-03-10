/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:57:05 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 19:36:21 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

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
