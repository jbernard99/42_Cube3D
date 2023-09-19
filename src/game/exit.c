/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:57:39 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/19 14:39:25 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"


int	ft_exit(t_game *input, char *msg)
{
	printf("%s", msg);
	mlx_terminate(input->mlx);
//	ft_freetabstr(input->mlx);
	return (EXIT_SUCCESS);
}
