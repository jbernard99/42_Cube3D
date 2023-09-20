/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:13:30 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/19 16:06:54 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

//t_frame *init_frame(t_game *game, t_frame *frame, void *mlx)
//{
//	frame = ft_calloc(1, sizeof(t_frame));
//	frame->img = mlx_new_image(mlx, sW, sH);
////	frame->addr = mlx_get_frame_addr(frame->img, game->s->bits_per_pixel, game->s->line_length, game->s->endian);
//	frame->s = game->s;
//
//	return (frame);
//}
//
//void	putpixel(t_frame *frame, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = frame->addr + (y * frame->s->line_length + x * (frame->s->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}
//


int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}