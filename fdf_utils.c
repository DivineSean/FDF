/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:15:39 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 14:17:21 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_mesure(t_vars *vars)
{
	vars->rotate_x = 1;
	vars->rotate_y = 1;
	vars->projection = 1;
	vars->shift_x = 1920 / 2;
	vars->shift_y = 1080 / 2;
}

void	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
			&vars->line_length, &vars->endian);
	win_mesure(vars);
}

void	mlx_hook_loop(t_vars *vars)
{
	mlx_hook(vars->win, 2, (1L << 0), controling_windows, vars);
	mlx_hook(vars->win, 17, 0, exit_handler, vars);
	mlx_loop(vars->mlx);
}

void	mallocing_spaces(t_vars *vars, char **spliter)
{
	int	i;

	i = 0;
	vars->z = malloc(sizeof(int *) * (vars->height + 1));
	vars->color = malloc(sizeof(int *) * (vars->height + 1));
	vars->x = malloc(sizeof(int *) * (vars->height + 1));
	my_set_x_y(vars);
	while (i < vars->height)
	{
		vars->x[i] = calcul_width(spliter[i]);
		if (i > 0 && vars->x[i] < vars->x[i - 1] - 6)
			my_error(vars, i);
		vars->z[i] = malloc(sizeof(int) * (vars->x[i]));
		vars->color[i] = malloc(sizeof(int) * (vars->x[i]));
		i++;
	}
	vars->z[i] = NULL;
	vars->color[i] = NULL;
}

void	filling_map_array(t_vars *vars, char **spliter)
{
	int	i;

	i = 0;
	calcul_x_y(vars, spliter);
	mallocing_spaces(vars, spliter);
	while (i < vars->height)
	{
		adding_num(vars, spliter[i], i);
		free(spliter[i]);
		i++;
	}
	free(spliter);
}
