/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:24:28 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 16:50:46 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_player *init_player(t_player *player)
{
	player = ft_calloc(1, sizeof(t_player));
	player->pos[0] = startPosX;
	player->pos[1] = startPosY;
	player->dir[0] = 0;
	player->dir[0] = 0;
	player->plane[0] = 0;
	player->plane[0] = 0;

	return (player);
}
