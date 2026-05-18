/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:42:59 by lperalta          #+#    #+#             */
/*   Updated: 2026/05/14 15:56:35 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_BONUS_H
# define CUBED_BONUS_H

# include "cubed.h"

# define MINIMAP_SCALE  8
# define MINIMAP_RADIUS 8

//BONUS RENDER
void	draw_minimap(t_game *game);

//BONUS INPUT
void	handle_mouse(t_game *game);

#endif