/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_x_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:04:37 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 14:39:33 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calcul_height(char **spliter)
{
	int	i;
	int	count;

	i = 0;
	while (spliter[i])
	{
		count = 0;
		while (spliter[i][count] == ' ' || spliter[i][count] == '\t')
			count++;
		if (ft_strlen(spliter[i]) == (size_t)count)
			return (i);
		i++;
	}
	return (i);
}

int	calcul_width(char *spliter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!spliter)
		return (0);
	while (spliter[i])
	{
		while ((spliter[i] && spliter[i] < '0') || \
		(spliter[i] && spliter[i] > '9'))
			i++;
		if ((spliter[i] && spliter[i] >= '0' && spliter[i] <= '9'))
		{
			while ((spliter[i] && spliter[i] >= '0' && spliter[i] <= '9'))
				i++;
			if (spliter[i] == ',')
				i++;
			while (ft_isnum(spliter[i]) || ft_isalpha(spliter[i]))
				i++;
			count++;
		}
	}
	return (count);
}

void	calcul_x_y(t_vars *vars, char **maps)
{
	int	i;
	int	count;
	int	big;

	i = 0;
	big = 0;
	while (maps[i])
	{
		count = calcul_width(maps[i]);
		if (big < count)
			big = count;
		i++;
	}
	vars->width = big;
	vars->height = calcul_height(maps);
	return ;
}
