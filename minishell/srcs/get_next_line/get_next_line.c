/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:41:11 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/19 15:54:49 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cpy(char *str, char **line, int i)
{
	*line = ft_substr_gnl(str, 0, i);
	i++;
	ft_memcpy(str, str + i, ft_strlen_const(str + i) + 1);
	return (1);
}

int	ft_longline(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_read(int *char_read, int fd, char **buffer)
{
	*char_read = read(fd, *buffer, 32);
	return (*char_read);
}

int	more_lines(char *str, char *buffer, char **line, int char_read)
{
	char	*tmp;

	if (str)
		tmp = ft_strdup(str);
	else
		tmp = ft_strdup("");
	free(str);
	free(buffer);
	str = NULL;
	*line = tmp;
	return (char_read);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*str = NULL;
	int				newline_i;
	int				char_read;

	buffer = malloc(sizeof(char) * 33);
	if (buffer == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	if (!line || fd < 0 || 32 < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (str)
		newline_i = ft_longline(str);
	if (str && newline_i > -1)
		return (ft_cpy(str, line, newline_i));
	while (ft_read(&char_read, fd, &buffer) > 0)
	{
		buffer[char_read] = '\0';
		str = ft_strjoin_gnl(str, buffer);
		newline_i = ft_longline(str);
		if (newline_i > -1)
			free(buffer);
		if (newline_i > -1)
			return (ft_cpy(str, line, newline_i));
	}
	return (more_lines(str, buffer, line, char_read));
}
