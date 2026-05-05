/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:31:10 by anzarago          #+#    #+#             */
/*   Updated: 2026/05/05 20:34:16 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	ft_freematrix_i(char **str, int ind)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str && i < ind)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
