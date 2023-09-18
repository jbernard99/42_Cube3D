/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:00:11 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 17:16:51 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void swap_img(t_data *data)
{
	void	*tmp;

	tmp = data->img;
	data->img = data->temp_img;
	data->temp_img = tmp;
}

void clear_img(t_data *data, void *mlx)
{
	free(data->temp_img);
	data->temp_img = mlx_new_image(mlx, sW, sH);
	return	
}