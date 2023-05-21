/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:03:32 by markik            #+#    #+#             */
/*   Updated: 2023/05/19 18:26:39 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_zoom(t_vars *vars, float *beginX, float *beginY)
{
	if (vars->zoom_x > 700)
		vars->zoom_x = vars->zoom_x - 10;
	if (vars->zoom_y > 700)
		vars->zoom_y = vars->zoom_y - 10;
	*beginX *= vars->zoom_x;
	*beginY *= vars->zoom_y;
	vars->endx *= vars->zoom_x;
	vars->endy *= vars->zoom_y;
}

void	draw_line_shift(t_vars *vars, float *beginX, float *beginY)
{
	*beginX += vars->shift_x;
	*beginY += vars->shift_y;
	vars->endx += vars->shift_x;
	vars->endy += vars->shift_y;
}

void	draw_line_delta(t_vars *vars, float beginX, float beginY)
{
	vars->deltax = (int)(vars->endx - beginX);
	vars->deltay = (int)(vars->endy - beginY);
	vars->pixels = isqrt((vars->deltax * vars->deltax) + \
			(vars->deltay * vars->deltay));
	vars->deltax /= vars->pixels;
	vars->deltay /= vars->pixels;
}

void	draw_line(t_vars *vars, float beginX, float beginY, int i)
{
	int	dem_z[2];

	init_end_x_y(vars, beginX, beginY, i);
	dem_z[0] = vars->z[(int)beginY][(int)beginX] * vars->projection;
	dem_z[1] = vars->z[(int)vars->endy][(int)vars->endx] * vars->projection;
	draw_line_zoom(vars, &beginX, &beginY);
	isometric(vars, &beginX, &beginY, dem_z[0]);
	isometric(vars, &vars->endx, &vars->endy, dem_z[1]);
	draw_line_shift(vars, &beginX, &beginY);
	draw_line_delta(vars, beginX, beginY);
	while ((int)(beginX - vars->endx) || (int)(beginY - vars->endy))
	{
		mlx_pixel_put(vars->mlx, vars->win, beginX, \
				beginY, vars->current_color);
		beginX += vars->deltax;
		beginY += vars->deltay;
	}
}
