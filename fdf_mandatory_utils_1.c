/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mandatory_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:15:23 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 16:15:24 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	making_spaces(t_vars *vars)
{
	int	i;

	i = 0;
	vars->z = malloc(sizeof(int *) * (vars->height + 1));
	while (i < vars->height)
	{
		vars->z[i] = malloc(sizeof(int) * (vars->width));
		i++;
	}
	vars->z[i] = NULL;
}

void	map_array(t_vars *vars, char **spliter)
{
	int	i;

	i = 0;
	calcul_x_y(vars, spliter);
	making_spaces(vars);
	while (i < vars->height)
	{
		_num(vars, spliter[i], i);
		free(spliter[i]);
		i++;
	}
	free(spliter);
}

void	_my_free(t_vars *vars)
{
	int	i;

	i = vars->height;
	while (i >= 0)
	{
		free(vars->z[i]);
		i--;
	}
	free(vars->z);
}

void	mlx_hook_loop_mandatory(t_vars *vars)
{
	mlx_hook(vars->win, 2, (1L << 0), controling_windows_man, vars);
	mlx_hook(vars->win, 17, 0, exit_handler, vars);
	mlx_loop(vars->mlx);
}

int	exit_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
