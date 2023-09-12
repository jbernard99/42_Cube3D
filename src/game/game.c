/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/09 21:27:12 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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