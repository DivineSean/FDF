/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:42 by markik            #+#    #+#             */
/*   Updated: 2023/05/19 18:39:38 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_error(t_vars *vars, int i)
{
	write(2, "The map Math path is incorrect\n", 32);
	vars->height = i + 1;
	my_free(vars);
	exit(0);
}

void	my_set_x_y(t_vars *vars)
{
	if (vars->height < 100 || vars->width < 100)
	{
		vars->zoom_y = vars->height;
		vars->zoom_x = vars->width;
	}
	else
	{
		vars->zoom_y = 2;
		vars->zoom_x = 2;
	}	
}

void	adding_num(t_vars *vars, char *line, int j)
{
	char	**string;
	char	*str;
	int		i;

	i = vars->x[j] - 1;
	string = ft_split(line, ' ');
	while (i >= 0)
	{
		vars->z[j][i] = ft_atoi(string[i]);
		vars->z[j][i] = ft_abs(vars->z[j][i]);
		str = ft_strcolor(string[i]);
		vars->color[j][i] = ft_atoi_base(str);
		free(string[i]);
		i--;
	}
	free(string);
}
