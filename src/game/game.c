/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:25:17 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/22 11:39:55 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int **init_map(int map_h)
{
	int	**m;
	
	m = ft_calloc(map_h, sizeof(int*));
	
	return (m);
}

void add_line(t_game *game, char *temp, int y)
{
	int static 	max_len = 0;
	int			i;

	i = ft_strlen(temp);
	if (i > max_len)
		max_len = i;
	game->m.map[y] = ft_calloc(i, sizeof(int)); // WHAT TO DO HERE IF size < max_len, and extra for '\0'?
	i = 0;
	while (temp[i] != '\0')
	{
		game->m.map[y][i] = temp[i];
		if (game)
		i++;
	}
	game
	game->m.map[y]
}

t_game init_game(t_settings *s)
{
	t_game	game;

	game.player = init_player(s);
	game.mlx = mlx_init(s->scrn_w, s->scrn_h, "Forza Horizon 6", false);
	game.img = mlx_new_image(game.mlx, s->scrn_w, s->scrn_h);
	game.s = s;
	game.is_playing = 0;
	game.old_time = 0;
	game.time = 0;

	return (game);
}
