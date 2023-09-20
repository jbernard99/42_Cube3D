/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:57:39 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/19 16:02:18 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

// ****CURRENTLY NOT USED

int	ft_exit(t_game *input, char *msg)
{
	printf("%s", msg);
//	ft_freetabstr(input->mlx);
	mlx_terminate(input->mlx);
	return (EXIT_SUCCESS);
}
