/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/21 14:29:10 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"
#include <stdio.h>

void	extract_file(char **argv, t_game *game)
{
	char	*temp;
	int		fd;

game->is_playing = 0; // temporary just to let the program compile MUST REMOVE!
	fd = open(argv[0], O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("%s", temp);
		temp = get_next_line(fd);
		/*
		if (temp && ft_strnstr(temp, "NO", 2) != 0)
		else if (temp && ft_strnstr(temp, "SO", 2) != 0)
		else if (temp && ft_strnstr(temp, "EA", 2) != 0)
		else if (temp && ft_strnstr(temp, "WE", 2) != 0)
		*/
			printf("This is NO texture : %s\n", temp);
	}
}
