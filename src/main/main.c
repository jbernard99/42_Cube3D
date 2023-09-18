/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/18 16:15:21 by smayrand         ###   ########.fr       */
=======
/*   Updated: 2023/09/18 15:54:49 by jbernard         ###   ########.fr       */
>>>>>>> 372e371e565bc226282071eb56fec6bc0082d9cb
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

// MLX prototypes
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.screen = mlx_new_window(game.mlx, screenWidth, screenHeight, "Forza Horizon 6");
//	game = init_game(&game, game.screen, game.mlx);
	mlx_hook(game.screen, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.screen, ON_DESTROY, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}