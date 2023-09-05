/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/05 15:26:45 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// MLX prototypes
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

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

t_game *init_game(t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	game->player = init_player(game->player);
	game->is_playing = 0;
	game->old_time = 0;
	game->time = 0;

	return (game);
}

int main(void)
{
	t_game	*game;
	
	game = init_game(&game);
	return (0);
}