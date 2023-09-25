/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:08:27 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/25 13:19:31 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"
#include <stdio.h>

/*
void	add_line(t_game *game, char *temp, int y)
{
	int static 	max_len = 0;
	int			i;
	
	
	i = ft_strlen(temp);
	write(1, "1\n", 2);
	if (i > max_len)
		max_len = i;
	s->m->map[y] = ft_calloc(i + 1, sizeof(int)); // WHAT TO DO HERE IF size < max_len, and extra for '\0'?
	write(1, "2\n", 2);
	i = 0;
	while (temp[i] != '\0')
	{
		s->m->map[y][i] = temp[i];
		i++;
	}
	s->m->map[y][i] = '\0';
}
*/
char	*trim_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && (line[i] != '.' && ft_isdigit(line[i]) == 0))
		i++;
	return (ft_strdup(&line[i]));
}

void	gather_map(t_settings *s, char *line)
{
	s->map_h++;
	s->m.temp = ft_strjoin(s->m.temp, line);
}

void	extract_file(char **argv, t_settings *s)
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
		//write(1, "1\n", 2);
		if (temp[0] == '1')
		{
			write(1, "2\n", 2);
			gather_map(s, temp);
		}
		else if (ft_strnstr(temp, "NO", 2) != 0)
			s->m.no = trim_path(temp);
		else if (ft_strnstr(temp, "SO", 2) != 0)
			s->m.so = trim_path(temp);
		else if (ft_strnstr(temp, "EA", 2) != 0)
			s->m.ea = trim_path(temp);
		else if (ft_strnstr(temp, "WE", 2) != 0)
			s->m.we = trim_path(temp);
		else if (ft_strnstr(temp, "C", 1) != 0)
			s->m.c = trim_path(temp);
		else if (ft_strnstr(temp, "F", 1) != 0)
			s->m.f = trim_path(temp);
		temp = get_next_line(fd);
	}
	write(1, "3\n", 2);
	printf("*%d*\n", s->map_h);
	printf("*%s*\n", s->m.temp);

	/*
	printf("\n%s\n", s->m->no);
	printf("\n%s\n", s->m->so);
	printf("\n%s\n", s->m->ea);
	printf("\n%s\n", s->m->we);
	printf("\n%s\n", s->m->c);
	printf("\n%s\n", s->m->f);
	*/
}
