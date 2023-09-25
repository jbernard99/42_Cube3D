/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plyr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:24:28 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/21 09:53:35 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_player init_player(t_settings *s)
{
	t_player	plyr;
	
	plyr.pos[0] = s->strt_posx;
	plyr.pos[1] = s->strt_posy;
	plyr.dir[0] = 0;
	plyr.dir[1] = 0;
	plyr.plane[0] = 0;
	plyr.plane[1] = 0.66;

	return (plyr);
}

int	find_start_pos(t_game *data)
{
	int	x;
	int	y;

	data->s->m.p_flag = 0;
	x = 0;
	y = 0;
	while (data->s->m.map[y])
	{
		while (data->s->m.map[y][x] == '\n')
		{
			if (ft_strchr("NSWE", data->s->m.map[y][x]) == 0)
			{
				data->s->m.p_flag++;
				data->player.pos_x = x;
				data->player.pos_y = y;
			}
			x++;
		}
		y++;
	}
	if (data->s->m.p_flag != 1)
		return (printf("\n%s\n", "Error: 0 or more than 1 player on the map"), 0);
	else
	return (printf("\n%s\n", "FU"),1);
}
