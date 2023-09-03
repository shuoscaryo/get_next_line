/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:15:39 by orudek            #+#    #+#             */
/*   Updated: 2023/04/18 21:51:32 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char			*get_next_line(int fd);
unsigned int	ft_strlen(const char *str);
unsigned char	ft_strchr(const char *str, char c);
char			ft_strjoin(char **str, const char *buf, unsigned int size);
void			ft_strlcpy(char *dst, const char *src, unsigned int size);
char			ft_free(char *str);

#endif