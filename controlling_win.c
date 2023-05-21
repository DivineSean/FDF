/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlling_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:00 by markik            #+#    #+#             */
/*   Updated: 2023/05/18 23:50:25 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	controling_windows(int keycode, t_vars *vars)
{
	shifting(vars, keycode);
	zooming(vars, keycode);
	rotating(vars, keycode);
	projection(vars, keycode);
	zooming_bonus(vars, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		my_free(vars);
		exit(0);
	}
	mlx_clear_window(vars->mlx, vars->win);
	matching_the_map(vars);
	return (0);
}

int	exit_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
