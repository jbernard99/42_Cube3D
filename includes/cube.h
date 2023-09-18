/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:21:48 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/18 17:13:16 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include "mlx.h"
# include "../libraries/42_libft/include/libft.h"

# define mapWidth 24
# define mapHeight 24
# define sW 640
# define sH 480

# define startPosX 13
# define startPosY 13

enum {
	KEY_UP = 126,
	KEY_LEFT = 123,
	KEY_DOWN = 125,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
	FAC = 16777216,
};

typedef struct s_player{
	double	pos[2];
	double	dir[2];
	double	plane[2];
//Feel Free to use
	double		pos_x; // position of the player
	double		pos_y; // position of the player
	double		dir_x; // value between -1 and 1 to initialize camera facing position
	double		dir_y; // value between -1 and 1 to initialize camera facing position
	double		plane_x; // must be equal to 0
	double		plane_y; // must be equal to 0.66
	char		set_dir;
	double		angle;
	double		speed;
}	t_player;

typedef struct s_game{
	t_player	*player;
	void		*mlx;
	void		*screen;
	int			is_playing;
	double		time;
	double		old_time;
}	t_game;
// exit.c
int			ft_exit(t_game *input, char *msg);

// game.c
t_game		*init_game(t_game *game, void *screen, void *mlx);

// player.c
t_player	*init_player(t_player *player);

// key_hook.c
int			key_hook(int keycode, t_game *input);

#endif