/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:01:26 by markik            #+#    #+#             */
/*   Updated: 2022/12/10 01:01:35 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
void	ft_strcat(char *str, char *dest, char *src);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(char *s, int c);
char	*ft_reading_to_stock(int fd, char *stock);
char	*ft_liner(char *stock);
char	*ft_stockage(char *stock);
char	*get_next_line(int fd);

#endif