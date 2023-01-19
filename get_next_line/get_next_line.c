/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:04:44 by cjullien          #+#    #+#             */
/*   Updated: 2021/01/09 17:56:22 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*str;
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
		str = stock_prev_read(buffer, str);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (i <= 0 && !str)
	{
		*line = ft_strdup("");
		return (i);
	}
	str = check_if_newline(line, str);
	return (last_check(i, str));
}
