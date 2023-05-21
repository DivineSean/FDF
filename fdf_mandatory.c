/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mandatory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:56:27 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 16:11:00 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	controling_windows_man(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		_my_free(vars);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**maps;

	if (ac == 1)
	{
		write(2, "Please put the map !\n", 22);
		return (0);
	}
	else if (ac > 2)
	{
		write(2, "Please put one MAP !\n", 22);
		return (0);
	}
	maps = map(av);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	map_array(&vars, maps);
	m_the_map(&vars);
	mlx_hook_loop_mandatory(&vars);
	return (0);
}
