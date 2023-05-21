/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <markik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:45 by markik            #+#    #+#             */
/*   Updated: 2023/05/18 20:35:04 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

char	*ft_strcolor(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (str + i + 3);
		i++;
	}
	return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	ft_digit(char c, int base)
{
	int	digit;

	digit = base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= digit)
		return (10 + c - 'a');
	return (-1);
}

int	ft_atoi_base(char *str)
{
	int	result;
	int	signe;
	int	digit;
	int	base;

	result = 0;
	signe = 1;
	base = 16;
	if (!str)
		return (0);
	if (*str == '-')
	{
		signe = -1;
		++str;
	}
	digit = ft_digit(to_lower(*str), base);
	while (digit >= 0)
	{
		result = result * base;
		result = result + (digit * signe);
		++str;
		digit = ft_digit(to_lower(*str), base);
	}
	return (result);
}
