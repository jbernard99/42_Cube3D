/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/20 13:42:35 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"
#include <stdio.h>

void	extract_file(char **argv, t_game *game)
{
	char	*temp;
	int		fd;

game->is_playing = 0; // temporary just to let te program compile MUST REMOVE!
	fd = open(argv[0], O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("%s", temp);
		temp = get_next_line(fd);
	}
}
