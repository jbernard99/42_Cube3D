/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/21 15:59:53 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cube.h"
#include <stdio.h>

char	*trim_path(char *line)
{
	int	i;

	i = -1;
	while (line[i] && (line[i] != '.' || ft_isdigit(line[i]) == 0 ))
		i++;
	return (ft_strdup(&line[i]));
}

void	extract_file(char **argv, t_game *game)
{
	char	*temp;
	int		fd;

	fd = open(argv[0], O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("%s", temp);
		temp = get_next_line(fd);

		if (temp && ft_strnstr(temp, "NO", 2) != 0)
			game->m.no = trim_path(temp);
		else if (temp && ft_strnstr(temp, "SO", 2) != 0)
			game->m.so = trim_path(temp);
		else if (temp && ft_strnstr(temp, "EA", 2) != 0)
			game->m.ea = trim_path(temp);
		else if (temp && ft_strnstr(temp, "WE", 2) != 0)
			game->m.we = trim_path(temp);
		else if (temp && ft_strnstr(temp, "C", 1) != 0)
			game->m.c = ft_strdup(&temp[2]);
		else if (temp && ft_strnstr(temp, "F", 1) != 0)
			game->m.c = ft_strdup(&temp[2]);
	}
	printf("\n%s\n", game->m.f);
	printf("\n%s\n", game->m.so);
}
