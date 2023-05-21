/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:58 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 14:09:59 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_free(t_vars *vars)
{
	int	i;

	i = vars->height;
	while (i >= 0)
	{
		free(vars->z[i]);
		free(vars->color[i]);
		i--;
	}
	free(vars->z);
	free(vars->color);
	free(vars->x);
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
	win_init(&vars);
	filling_map_array(&vars, maps);
	matching_the_map(&vars);
	mlx_hook_loop(&vars);
	return (0);
}
