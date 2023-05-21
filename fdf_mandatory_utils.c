/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mandatory_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:03:24 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 16:10:05 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_init_end_x_y(t_vars *vars, float beginX, float beginY, int i)
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
	if (vars->z[(int)beginY][(int)beginX] > 0 || \
			vars->z[(int)vars->endy][(int)vars->endx] > 0)
		vars->current_color = 0x0000FF00;
	else
			vars->current_color = 0xFFFFFF;
}

void	_isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.5) + z;
	*y = -z + (previous_x + previous_y) * sin(0.5);
}

void	draw_line_mandatory(t_vars *vars, float beginX, float beginY, int i)
{
	int	dem_z[2];

	_init_end_x_y(vars, beginX, beginY, i);
	dem_z[0] = vars->z[(int)beginY][(int)beginX] * 2;
	dem_z[1] = vars->z[(int)vars->endy][(int)vars->endx] * 2;
	beginX *= vars->width * 2;
	beginY *= vars->height * 2;
	vars->endx *= vars->width * 2;
	vars->endy *= vars->height * 2;
	beginX += 1920 / 2 + (vars->width) * 2;
	vars->endx += 1920 / 2 + (vars->width) * 2;
	_isometric(&beginX, &beginY, dem_z[0]);
	_isometric(&vars->endx, &vars->endy, dem_z[1]);
	draw_line_delta(vars, beginX, beginY);
	while ((int)(beginX - vars->endx) || (int)(beginY - vars->endy))
	{
		mlx_pixel_put(vars->mlx, vars->win, beginX, \
				beginY, vars->current_color);
		beginX += vars->deltax;
		beginY += vars->deltay;
	}
}

void	m_the_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (x < vars->width - 1)
				draw_line_mandatory(vars, x, y, 0);
			if (y < vars->height - 1 && vars->width != x)
				draw_line_mandatory(vars, x, y, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 1920, 1080);
}

void	_num(t_vars *vars, char *line, int j)
{
	char	**string;
	int		i;

	i = vars->width - 1;
	string = ft_split(line, ' ');
	while (i >= 0)
	{
		vars->z[j][i] = ft_atoi(string[i]);
		vars->z[j][i] = ft_abs(vars->z[j][i]);
		free(string[i]);
		i--;
	}
	free(string);
}
