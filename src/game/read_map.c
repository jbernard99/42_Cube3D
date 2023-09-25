/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/22 13:26:01 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cube.h"
#include <stdio.h>

void	add_line(t_game *game, char *temp, int y)
{
	int static 	max_len = 0;
	int			i;
	
	
	i = ft_strlen(temp);
	write(1, "1\n", 2);
	if (i > max_len)
		max_len = i;
	game->m->map[y] = ft_calloc(i + 1, sizeof(int)); // WHAT TO DO HERE IF size < max_len, and extra for '\0'?
	write(1, "2\n", 2);
	i = 0;
	while (temp[i] != '\0')
	{
		game->m->map[y][i] = temp[i];
		i++;
	}
	game->m->map[y][i] = '\0';
}

char	*trim_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && (line[i] != '.' && ft_isdigit(line[i]) == 0))
		i++;
	return (ft_strdup(&line[i]));
}


void	extract_file(char **argv, t_game *game)
{
	char	*temp;
	int		fd;
	int 	y;

	y = 0;
	fd = open(argv[0], O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("%s\n", temp);
		temp = get_next_line(fd);
		if (temp != NULL)
		{
			if (temp[0] == '1')
				add_line(game, temp, y++);
			else if (ft_strnstr(temp, "NO", 2) != 0)
				game->m->no = trim_path(temp);
			else if (ft_strnstr(temp, "SO", 2) != 0)
				game->m->so = trim_path(temp);
			else if (ft_strnstr(temp, "EA", 2) != 0)
				game->m->ea = trim_path(temp);
			else if (ft_strnstr(temp, "WE", 2) != 0)
				game->m->we = trim_path(temp);
			else if (ft_strnstr(temp, "C", 1) != 0)
				game->m->c = trim_path(temp);
			else if (ft_strnstr(temp, "F", 1) != 0)
				game->m->f = trim_path(temp);
		}
	}
	/*
	printf("\n%s\n", game->m->no);
	printf("\n%s\n", game->m->so);
	printf("\n%s\n", game->m->ea);
	printf("\n%s\n", game->m->we);
	printf("\n%s\n", game->m->c);
	printf("\n%s\n", game->m->f);
	*/
}
