/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:51:20 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 20:07:32 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int main(int argc, char **argv)
{
	int fd;
	//t_scene data;
	
	if(argc != 2)
		return(1);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0 || check_file(argv[1]) == FALSE)
		return(1); //cambiar return por función de error con mensaje personalizado y cerrar fd	
	/*data = init(argv[1]);
	if(!data)
		return(1);
	destroy(&data);*/
	return(0);
}