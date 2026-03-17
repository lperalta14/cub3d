/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:51:20 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/17 15:27:06 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int main(int argc, char **argv)
{
	int fd;
	t_scene data;
	
	if(argc != 2)
		return(1);
	if(check_file(argv[1]) == FALSE) // lo miramos juntos
	{
		clean_error(&data, FILE, FALSE);
		return(1);
	}
	//no tiene mas sentido abrir el fd en init y que asi si falla cierre ahi
	ft_bzero(&data, (sizeof(t_scene))); // me lo he copiado de tu so_long
	if (init_data(&data, argv[1]) == TRUE)
		start_game(); //por hacer
	else
	{
		clean_error(&data, INIT, TRUE); // por ejemplo, que borre, ponga msg con enum y true para que sepa que tiene que limpiar data
		return(1);
	}
	clean_data(&data);
	return(0);
}