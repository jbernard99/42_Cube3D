/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/21 11:00:11 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/*
void	init_game_frames(t_game *game)
{
	int	i;

	game->s = ft_calloc(1, sizeof(t_settings));
	game->curr_frame = ft_calloc(1, sizeof(t_frame));
//	game->curr_frame = init_frame(game, game->curr_frame, game->mlx);
	i = 0;
	while (i < 5)
	{
//		game->pre_frames[i] = init_frame(game, game->pre_frames[i], game->mlx);
		i++;
	}
}
*/

t_game init_game(t_settings *s)
{
	t_game	game;

	game.player = init_player(s);
	game.mlx = mlx_init(s->scrn_w, s->scrn_h, "Forza Horizon 6", true);
	game.img = mlx_new_image(game.mlx, s->scrn_w, s->scrn_h);
	game.s = s;
	game.is_playing = 0;
	game.old_time = 0;
	game.time = 0;

	return (game);
}
