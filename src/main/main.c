/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/20 13:39:14 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"
#include <stdlib.h>

// MLX prototypes
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

t_settings init_settings()
{
	t_settings settings;
	
	settings.map_w = 24;
	settings.map_h = 24;
	settings.scrn_w = 640;
	settings.scrn_h = 480;
	settings.strt_posx = 13;
	settings.strt_posy = 13;

	return (settings);
}

int main(int argc, char **argv)
{
	(void)argv;
	t_settings	settings;
	t_game		game;

	settings = init_settings();
	if (argc != 2)
	{
		game.mlx = mlx_init(sW, sH, "Forza Horizon 6", true);
//		game.screen = mlx_new_window(game.mlx, sW, sH, "Forza Horizon 6");
//		init_game(&game, game.screen, game.mlx);
//		mlx_key_hook(game.screen, 2, 1L << 0, key_hook, &game);
//		mlx_key_hook(game.screen, ON_DESTROY, 0, ft_exit, &game);
		mlx_key_hook(game.mlx, &key_hook, NULL);
		mlx_loop(game.mlx);
		printf("%s\n", "Game Closed");
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("%s\n", "Error: Invalid number of arguments");
	}
}
