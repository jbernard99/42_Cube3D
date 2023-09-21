/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/21 11:03:33 by jbernard         ###   ########.fr       */
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

void paint_screen(t_game *game)
{
	uint32_t	rgba;
	int w;
	int h;

	rgba = get_rgba(100, 1, 175, 1);
	h = 0;
	while (h < game->s->scrn_h)
	{
		w = 0;
		while (w < game->s->scrn_w)
		{
			mlx_put_pixel(game->img, w, h, (uint32_t)rgba);
			w++;
		}
		h++;
	}
}

static void ft_hook(void *param)
{
	t_game *game;

	game = param;
}

int main(int argc, char **argv)
{
	t_settings	settings;
	t_game		game;

	printf("ARGC: %d\n", argc);
	printf("ARGV[2]: %s\n", argv[1]);
	if (argc == 2)
	{
		validate_ext(argv[1]);
		extract_file(&argv[1], &game);
		settings = init_settings();
		game = init_game(&settings);
		mlx_key_hook(game.mlx, &key_hook, &game);
		
		// ---- //

		paint_screen(&game);
		if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
			printf("Error with game.img\n");

		// ---- //
		
		mlx_loop_hook(game.mlx, ft_hook, (void*)&game);
		mlx_loop(game.mlx);
		printf("Game Closed after %f ft_hook ticks\n", game.time);
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("%s\n", "Error: Invalid number of arguments");
	}
}
