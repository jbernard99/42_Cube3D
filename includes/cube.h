/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:21:48 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/09 21:29:19 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <mlx.h>
#include "../libraries/42_libft/include/libft.h"

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

# define startPosX 13
# define startPosY 13

typedef struct s_player{
	double	pos[2];
	double	dir[2];
	double	plane[2];
}	t_player;
 
typedef struct s_game{
	t_player	*player;
	void		*mlx;
	void		*screen;
	int			is_playing;
	double		time;
	double		old_time;
}	t_game;

// game.c
t_game		*init_game(t_game *game, void *screen, void *mlx);

// player.c
t_player	*init_player(t_player *player);

#endif