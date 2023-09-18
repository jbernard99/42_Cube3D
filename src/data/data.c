/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:13:30 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 17:23:12 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_data *init_data(t_data *data, void *mlx)
{
	data = ft_calloc(1, sizeof(t_data));
	data->img = mlx_new_image(mlx, sW, sH);
	data->addr = mlx_get_data_addr(data->img, data->bits_per_pixel, data->line_length, data->endian);

	return (data);
}

void	putpixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
