/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:34:47 by anzarago          #+#    #+#             */
/*   Updated: 2026/03/10 16:55:10 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_scene init(char *argv)
{
	t_scene conf;
	conf.fd = open(argv);
	if(conf.fd < 0 )
		return();
}