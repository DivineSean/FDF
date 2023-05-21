/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:24:52 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 14:37:56 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*map_utils(int fd, char *joined)
{
	char	*buffer;
	char	*buffer2;

	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
		{
			free(buffer);
			break ;
		}
		buffer2 = get_next_line(fd);
		if (!buffer2)
		{
			if (joined == NULL)
				joined = ft_strdup(buffer);
			else
				joined = ft_strjoiness(joined, buffer);
			free(buffer);
			break ;
		}
		joined = map_utils_1(joined, buffer, buffer2);
	}
	return (joined);
}

char	*map_utils_1(char *joined, char *buffer, char *buffer2)
{
	if (joined == NULL)
		joined = ft_strjoiness(buffer, buffer2);
	else
	{
		joined = ft_strjoiness(joined, buffer);
		joined = ft_strjoiness(joined, buffer2);
		free(buffer);
	}
	free(buffer2);
	return (joined);
}

char	*map_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '.' && str[i + 1] == 'f' && \
				str[i + 2] == 'd' && str[i + 3] == 'f')
			return (str + i);
		i--;
	}
	return (NULL);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char	**map(char **av)
{
	char	**spliter;
	char	*joined;
	char	*mp_name;
	int		fd;

	joined = NULL;
	mp_name = map_name(av[1]);
	if (!mp_name)
	{
		putstr(av[1]);
		write(2, ": Only .fdf file supported \n", 29);
		exit(0);
	}
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		perror(av[1]);
		exit(0);
	}
	joined = map_utils(fd, joined);
	close(fd);
	spliter = ft_split(joined, '\n');
	free(joined);
	return (spliter);
}
