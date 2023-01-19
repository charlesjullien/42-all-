/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:14:49 by mabuchar          #+#    #+#             */
/*   Updated: 2021/01/28 14:21:57 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			ft_cpy(char *str, char **line, int i);
int			get_next_line(int fd, char **line);
int			ft_longline(const char *buffer);
int			ft_strlen_const(const char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_substr_gnl(char const *s, int start, int len);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
