/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:44:05 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/16 10:06:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_dot_cub(t_cub *cub, char *map)
{
	int	i;
	int	rd;
	int	buf;

	i = 0;
	rd = 1;
	buf = 1;
	while (map[i])
		i++;
	if (i < 5 || (map[i - 1] != 'b' || map[i - 2] != 'u'
			|| map[i - 3] != 'c' || map[i - 4] != '.'))
		ft_stop(EXIT_FAILURE, cub, "Error\nFile must be *.cub type");
	cub->fd = open(map, O_RDONLY);
	if (cub->fd < 0)
		ft_stop(EXIT_FAILURE, cub, "Error\nFailed to open *.cub file");
	i = 0;
	while (rd == 1)
	{
		rd = read(cub->fd, (char *)&buf, 1);
		i++;
	}
	cub->dot_cub = malloc(sizeof(char) * i + 1);
	if (cub->dot_cub == NULL)
		ft_stop(EXIT_FAILURE, cub, "Error\nFailed to malloc");
	close(cub->fd);
}

void	fill_from_dot_cub(t_cub *cub, char *map)
{
	int	rd;
	int	i;
	int	buf;

	rd = 1;
	i = 0;
	buf = 1;
	malloc_dot_cub(cub, map);
	cub->fd = open(map, O_RDONLY);
	if (cub->fd < 0)
		ft_stop(EXIT_FAILURE, cub, "Error\nFailed to open .cub file");
	while (rd == 1)
	{
		rd = read(cub->fd, (char *)&buf, 1);
		cub->dot_cub[i] = buf;
		if (rd == 1)
			i++;
	}
	cub->dot_cub[i] = '\0';
	close(cub->fd);
}

int	mini_gnl(char *map, t_cub *cub, int *j, int i)
{
	int	i_copy;

	while (map[i] && map[i] != '\n')
		i++;
	if (cub->line)
		free(cub->line);
	cub->line = NULL;
	cub->line = malloc(sizeof(char) * (i + 1));
	if (!cub->line)
		return (0);
	i_copy = i;
	i = 0;
	while (i < i_copy && map[i] && map[i] != '\n')
	{
		cub->line[i] = map[i];
		i++;
	}
	cub->line[i] = '\0';
	while (map[i] && map[i] == '\n')
		i++;
	*j = *j + i;
	if (map[i] == '\0' || map[i + 1] == '\0')
		return (0);
	return (1);
}
