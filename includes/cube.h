/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:21:48 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/20 13:43:40 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include "../libraries/42_libft/include/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

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

typedef struct s_settings {
	int			map_w;
	int			map_h;
	int			scrn_h;
	int			scrn_w;
	int			strt_posx;
	int			strt_posy
}	t_settings;

typedef struct s_mlx {
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*addr;
	t_settings 	*s;
}	t_mlx;
 
typedef struct s_game{
	t_player	*player;
	t_settings	*s;
	t_mlx		*mlx;
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

// frame.c
t_frame 	*init_frame(t_game *game, t_frame *frame, void *mlx);

// key_hook.c
void		key_hook(mlx_key_data_t keycode, void *input);

#endif