/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 13:34:43 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_game *init_game(t_game *game, void *screen, void *mlx)
{
	game = ft_calloc(1, sizeof(t_game));
	game->player = init_player(game->player);
	game->mlx = mlx;
	game->screen = screen;
	game->is_playing = 0;
	game->old_time = 0;
	game->time = 0;

	return (game);
}