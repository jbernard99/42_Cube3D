/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:25:22 by smayrand          #+#    #+#             */
/*   Updated: 2023/09/20 12:41:17 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	validate_ext(char *file)
{
	char	*ext;
	int		i;
	int		j;

	ext = ".cub";
	j = 0;
	i = ft_strlen(file) - 4;
	while (ext[j] != '\0')
	{
		if (file[i] != ext[j] || (i - 5) <= 0)
		{
			printf("%s", "Error: Wrong map extention\n");
			exit (0);
		}
		i++;
		j++;
	}
}
