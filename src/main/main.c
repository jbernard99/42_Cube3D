/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:04 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 13:34:52 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

// MLX prototypes
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int main(void)
{
	t_game	*game;
	void	*mlx;
	void	*screen;

	game = NULL;
	mlx = mlx_init();
	screen = mlx_new_window(mlx, screenWidth, screenHeight, "Forza Horizon 6");
	game = init_game(game, screen, mlx);
	mlx_loop(mlx);
	return (0);
}