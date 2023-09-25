/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/25 12:41:55 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_map	init_map(int map_h)
{
	t_map	m;

	m.map = ft_calloc(map_h, sizeof(int*));

	return (m);
}

t_game	init_game(t_settings *s)
{
	t_game	game;

	game.player = init_player(s);
	game.mlx = mlx_init(s->scrn_w, s->scrn_h, "Forza Horizon 6", false);
	game.img = mlx_new_image(game.mlx, s->scrn_w, s->scrn_h);
	game.m = init_map(5);
	game.s = s;
	game.is_playing = 0;
	game.old_time = 0;
	game.time = 0;

	return (game);
}
