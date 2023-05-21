/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:54:37 by markik            #+#    #+#             */
/*   Updated: 2023/05/20 16:06:58 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_vars
{
	double	pixels;
	float	rotate_x;
	float	rotate_y;
	float	deltax;
	float	deltay;
	float	endx;
	float	endy;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		current_color;
	int		width;
	int		*x;
	int		height;
	int		zoom_x;
	int		projection;
	int		zoom_y;
	int		**color;
	int		**z;
	int		shift_x;
	int		shift_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_vars;

char	**map(char **av);
void	my_free(t_vars *vars);
char	*map_utils(int fd, char *joined);
char	*map_utils_1(char *joined, char *buffer, char *buffer2);
char	*ft_strjoiness(char *s1, char *s2);
char	**ft_free(char **str, size_t j);
char	*ft_word(char const *s, char c);
char	**ft_split(char const *s, char c);
void	draw_line(t_vars *vars, float beginX, float beginY, int i);
void	draw_line_delta(t_vars *vars, float beginX, float beginY);
void	draw_line_shift(t_vars *vars, float *beginX, float *beginY);
void	draw_line_zoom(t_vars *vars, float *beginX, float *beginY);
void	init_end_x_y(t_vars *vars, float beginX, float beginY, int i);
void	init_color(t_vars *vars, float beginX, float beginY);
void	isometric(t_vars *vars, float *x, float *y, int z);
void	matching_the_map(t_vars *vars);
void	adding_num(t_vars *vars, char *line, int i);
void	calcul_x_y(t_vars *vars, char **maps);
size_t	ft_count_word(char const *s, char c);
size_t	ft_strlen_checker(char const *s, char c);
int		controling_windows(int keycode, t_vars *vars);
int		exit_handler(t_vars *vars);
int		exit_handler(t_vars *vars);
void	_init_end_x_y(t_vars *vars, float beginX, float beginY, int i);
void	_isometric(float *x, float *y, int z);
void	shifting(t_vars *vars, int keycode);
void	draw_line_mandatory(t_vars *vars, float beginX, float beginY, int i);
void	m_the_map(t_vars *vars);
void	making_spaces(t_vars *vars);
void	map_array(t_vars *vars, char **spliter);
void	_num(t_vars *vars, char *line, int j);
void	_my_free(t_vars *vars);
int		controling_windows_man(int keycode, t_vars *vars);
void	mlx_hook_loop_mandatory(t_vars *vars);
void	zooming(t_vars *vars, int keycode);
void	my_error(t_vars *vars, int i);
void	my_set_x_y(t_vars *vars);
void	zooming_bonus(t_vars *vars, int keycode);
void	win_init(t_vars *vars);
void	rotating(t_vars *vars, int keycode);
void	mlx_hook_loop(t_vars *vars);
void	projection(t_vars *vars, int keycode);
void	mallocing_spaces(t_vars *vars, char **spliter);
void	filling_map_array(t_vars *vars, char **spliter);
char	*ft_strcolor(char *str);
void	win_mesure(t_vars *vars);
char	to_lower(char c);
int		ft_isnum(char c);
int		ft_isalpha(char c);
int		calcul_height(char **spliter);
int		ft_digit(char c, int base);
int		ft_atoi_base(char *str);
int		calcul_width(char *spliter);
int		ft_abs(int x);
int		isspace3(const char *str);
int		ft_atoi(const char *str);
double	isqrt(double n);
#endif
