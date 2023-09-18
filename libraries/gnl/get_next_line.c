/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:15:07 by smayrand          #+#    #+#             */
/*   Updated: 2022/05/30 13:12:42 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rline(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		tmp[i] = '\n';
		i++;
	}
	return (tmp);
}

char	*ft_nextl(char *buffer)
{
	char	*tmp;
	int		i;
	int		ii;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	ii = 0;
	while (buffer[i])
		tmp[ii++] = buffer[i++];
	free(buffer);
	return (tmp);
}

char	*ft_bertin(char *thanks, char *tip)
{
	char	*temp;

	temp = ft_strjoin(thanks, tip);
	free(thanks);
	return (temp);
}

char	*ft_read(int fd, char *file)
{
	char	*buffer;
	int		nbread;

	if (!file)
		file = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbread = 1;
	while (nbread > 0)
	{
		nbread = read(fd, buffer, BUFFER_SIZE);
		if (nbread == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[nbread] = 0;
		file = ft_bertin(file, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_rline(buffer[fd]);
	buffer[fd] = ft_nextl(buffer[fd]);
	return (line);
}
