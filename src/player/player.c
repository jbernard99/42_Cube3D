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
	plyr.dir[0] = 0;
	plyr.plane[0] = 0;
	plyr.plane[0] = 0;

	return (plyr);
}
