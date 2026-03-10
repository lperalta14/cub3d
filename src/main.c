/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:51:20 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 19:24:42 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int main(int argc, char **argv)
{
	t_scene data;
	
	if(argc != 2 || check_file(argv[1]) == FALSE)
		return(1);
	data = init(argv[1]);
	if(!data)
		return(1);
	destroy(&data);
	return(0);
}