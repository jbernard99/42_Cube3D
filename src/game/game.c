/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/25 15:53:05 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	init_map_tab(t_map *m)
{
	int	max_len;
	int	i;
	int	x;
	int	y;

	x = 0;
	i = 0;
	y = 0;
	while (m->temp[i + x] != '\0')
	{
		printf("x : %d, y : %d, i : %d, c : %c\n", x, y, i, m->temp[i + x]);
		if (m->temp[i + x] == '\n')
		{
			if (x > max_len)
				max_len = x;
			m->map[y] = ft_strldup(&m->temp[i], x);
			i = i + x;
			x = 0;
			y++;
		}
		x++;
	}
}

t_game	init_game(t_settings *s)
{
	t_game	game;

	game.player = init_player(s);
	game.mlx = mlx_init(s->scrn_w, s->scrn_h, "Forza Horizon 6", false);
	game.img = mlx_new_image(game.mlx, s->scrn_w, s->scrn_h);
	game.s = s;
	s->m.map = ft_calloc(s->map_h, sizeof(char*));
	init_map_tab(&s->m);
	game.is_playing = 0;
	game.old_time = 0;
	game.time = 0;

	return (game);
}
