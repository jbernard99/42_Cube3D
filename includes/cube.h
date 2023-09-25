/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:21:48 by jbernard          #+#    #+#             */
/*   Updated: 2023/09/25 13:27:12 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libraries/42_libft/include/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define BUFFER_SIZE 100

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

typedef struct s_map {
	int		**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	char	*temp;
}	t_map;

typedef struct s_settings {
	int			map_w;
	int			map_h;
	int			map_r;
	int			scrn_h;
	int			scrn_w;
	int			strt_posx;
	int			strt_posy;
	t_map		m;
}	t_settings;
 
typedef struct s_game{
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				is_playing;
	double			time;
	double			old_time;
	t_settings		*s;
}	t_game;


// validate_ext.c
void		validate_ext(char *file);

// read_map.c
void		extract_file(char **argv, t_settings *s);

// game.c
t_game		init_game(t_settings *s);

// player.c
t_player	init_player(t_settings *s);

// colors.c
int get_rgba(int r, int g, int b, int a);
int get_r(int rgba);
int get_g(int rgba);
int get_b(int rgba);
int get_a(int rgba);

// key_hook.c
void		key_hook(mlx_key_data_t keycode, void *input);

// get_next_line_utils.c
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *hay, int needle);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *str);

// exit.c
int			ft_exit(t_game *input, char *msg);

#endif