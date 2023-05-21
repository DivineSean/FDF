/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:51 by markik            #+#    #+#             */
/*   Updated: 2023/05/19 18:41:58 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_vars *vars, float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	if (z >= 9000 || z < 0)
		z = 2000;
	*x = (previous_x - previous_y) * cos(0.5 * vars->rotate_x) + z;
	*y = -z + (previous_x + previous_y) * sin(0.5 * vars->rotate_y);
}

void	init_color(t_vars *vars, float beginX, float beginY)
{
	vars->current_color = vars->color[(int)beginY][(int)beginX];
	if (vars->current_color == 0)
	{
		if (vars->z[(int)beginY][(int)beginX] > 0 || \
				vars->z[(int)vars->endy][(int)vars->endx] > 0)
			vars->current_color = 0xFFFFFF;
		else
			vars->current_color = 0x0000FF00;
	}
}

void	init_end_x_y(t_vars *vars, float beginX, float beginY, int i)
{
	if (i == 0)
	{
		vars->endx = beginX + 1;
		vars->endy = beginY;
	}
	else if (i == 1)
	{
		vars->endx = beginX;
		vars->endy = beginY + 1;
	}
	init_color(vars, beginX, beginY);
}
