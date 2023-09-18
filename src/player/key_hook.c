/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/18 16:20:48 by smayrand         ###   ########.fr       */
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


int	key_hook(int keycode, t_game *input)
{
	if (keycode == KEY_ESC)
		ft_exit(input, "\033[34mGame closed\n\033[0m");
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_forward(input);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(input);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_backward(input);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(input);
	else
		printf("Error\nKey pressed is invalid. Keycode:%d\n", keycode);
	return (0);
}