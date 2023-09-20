/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/20 14:14:00 by jbernard         ###   ########.fr       */
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
	t_settings	settings;
	t_game		game;

	settings = init_settings();
	game = init_game(&settings);
	printf("ARGC: %d\n", argc);
	printf("ARGV[2]: %s\n", argv[1]);
	if (argc == 2)
	{
		validate_ext(argv[1]);
		extract_file(&argv[1], &game);
		mlx_key_hook(game.mlx, &key_hook, &game);
		mlx_loop(game.mlx);
		printf("\n%s\n", "Game Closed");
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("%s\n", "Error: Invalid number of arguments");
	}
}
