/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:25:08 by cjullien          #+#    #+#             */
/*   Updated: 2021/01/11 19:19:26 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*check_if_newline(char **line, char *str)
{
	char			*temp;
	int				i;
	int				len;

	i = get_index(str);
	len = ft_strlen(str);
	if (i < len)
	{
		*line = ft_substr(str, 0, i);
		temp = ft_substr(str, i + 1, len);
		free(str);
		str = ft_strdup(temp);
		free(temp);
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

char	*stock_prev_read(char *buffer, char *str)
{
	char	*temp;

	if (str)
	{
		temp = ft_strjoin(str, buffer);
		free(str);
		str = ft_strdup(temp);
		free(temp);
	}
	else
		str = ft_strdup(buffer);
	return (str);
}

int		last_check(int i, char *str)
{
	if (i <= 0 && !str)
		return (i);
	else
		return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[1024];
	char			buffer[BUFFER_SIZE + 1];
	int				i;

	i = 1;
	if (!line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (i);
		buffer[i] = '\0';
		str[fd] = stock_prev_read(buffer, str[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (i <= 0 && !str[fd])
	{
		*line = ft_strdup("");
		return (i);
	}
	str[fd] = check_if_newline(line, str[fd]);
	return (last_check(i, str[fd]));
}
