/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlling_win_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:32:43 by markik            #+#    #+#             */
/*   Updated: 2023/05/19 18:22:02 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shifting(t_vars *vars, int keycode)
{
	if (keycode == 126)
		vars->shift_y -= 20;
	else if (keycode == 125)
		vars->shift_y += 20;
	else if (keycode == 124)
		vars->shift_x += 20;
	else if (keycode == 123)
		vars->shift_x -= 20;
}

void	zooming(t_vars *vars, int keycode)
{
	if (keycode == 69)
	{
		vars->zoom_x += 10;
		vars->zoom_y += 10;
	}
	else if (keycode == 78)
	{
		vars->zoom_x /= 2;
		vars->zoom_y /= 2;
	}
}

void	rotating(t_vars *vars, int keycode)
{
	if (keycode == 91)
		vars->rotate_y += 2;
	else if (keycode == 84)
		vars->rotate_y -= 2;
	else if (keycode == 86)
		vars->rotate_x -= 2;
	else if (keycode == 88)
		vars->rotate_x -= 2;
}

void	zooming_bonus(t_vars *vars, int keycode)
{
	if (keycode == 13)
		vars->zoom_y += 10;
	else if (keycode == 0)
		vars->zoom_x -= 10;
	else if (keycode == 1)
		vars->zoom_y -= 10;
	else if (keycode == 2)
		vars->zoom_x += 10;
}

void	projection(t_vars *vars, int keycode)
{
	if (keycode == 47)
	{
			vars->projection *= 2;
		if (vars->projection == 0)
			vars->projection = 1;
	}
	else if (keycode == 43)
		vars->projection /= 2;
}
