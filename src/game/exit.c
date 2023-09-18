/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:57:39 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/18 16:00:00 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"


int	ft_exit(t_game *input, char *msg)
{
	printf("%s", msg);
	mlx_destroy_window(input->mlx, input->screen);
	ft_freetabstr(input->mlx);
	exit(0);
}
