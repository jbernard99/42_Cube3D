/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/20 13:35:10 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"
#include <stdlib.h>

// MLX prototypes
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int main(int argc, char **argv)
{
	(void)argv;
	t_game	game;
	
	printf("ARGC: %d\n", argc);
	printf("ARGV[2]: %s\n", argv[1]);
	if (argc == 2)
	{
		validate_ext(argv[1]);
		extract_file(&argv[1], &game);
		game.mlx = mlx_init(sW, sH, "Forza Horizon 6", true);
//		game.screen = mlx_new_window(game.mlx, sW, sH, "Forza Horizon 6");
//		init_game(&game, game.screen, game.mlx);
//		mlx_key_hook(game.screen, 2, 1L << 0, key_hook, &game);
//		mlx_key_hook(game.screen, ON_DESTROY, 0, ft_exit, &game);
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
