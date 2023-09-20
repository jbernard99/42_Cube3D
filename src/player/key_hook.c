/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/19 16:18:46 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	move_forward(t_game *game)
{
	(void)game;
}

void	move_backward(t_game *game)
{
	(void)game;
}

void	move_left(t_game *game)
{
	(void)game;
}

void	move_right(t_game *game)
{
	(void)game;
}


void	key_hook(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = param;
	if (keycode.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_UP)
		move_forward(param);
	else if (keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_LEFT)
		move_left(param);
	else if (keycode.key == MLX_KEY_S || keycode.key == MLX_KEY_DOWN)
		move_backward(param);
	else if (keycode.key == MLX_KEY_D || keycode.key == MLX_KEY_RIGHT)
		move_right(param);
	else
		printf("Error\nKey pressed is invalid. Keycode:%d\n", keycode.key);
	return ;
}