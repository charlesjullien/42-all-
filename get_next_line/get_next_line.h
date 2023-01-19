/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:08:36 by cjullien          #+#    #+#             */
/*   Updated: 2021/01/09 17:16:38 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int to_find);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);

#endif
