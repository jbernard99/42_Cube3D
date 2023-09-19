/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:00:11 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/19 11:22:16 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void swap_img(t_frame *f)
{
	
}

void clear_img(t_frame *f, void *mlx)
{
	free(data->temp_img);
	data->temp_img = mlx_new_image(mlx, sW, sH);
	
}