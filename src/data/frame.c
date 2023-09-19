/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:13:30 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/19 13:03:50 by smayrand         ###   ########.fr       */
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