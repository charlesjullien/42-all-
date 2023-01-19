/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:13:17 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/16 10:20:46 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_consecutive_nl(t_cub *cub, char *str)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
		else
			nl = 0;
		if (nl == 2)
			ft_stop(EXIT_FAILURE, cub, "Error\nWrong description or 2 nl.");
		i++;
	}
	i--;
	if (ft_strchr("1\n", str[i]) == 0)
		ft_stop(EXIT_FAILURE, cub, "Error\nWrong description or 2 nl.");
}

void	flood_fill_algo(t_cub *cub, int limit, int x, int y)
{
	if (x > cub->height - 1 || y > cub->width - 1 || x < 0 || y < 0
		|| y > ft_strlen(cub->map_orig[x]) || !cub->map_orig[x][y]
		|| cub->map_orig[x][y] == ' ')
		ft_stop(EXIT_FAILURE, cub, "Error\nMap doesn't fit criterias.");
	if (limit > 28000)
		ft_stop(EXIT_FAILURE, cub, "Error\nMap must be smaller.");
	if (cub->map_orig[x][y] != '0')
		return ;
	if (cub->map_orig[x][y] == 'F')
		return ;
	if (cub->map_orig[x][y] == '0')
		cub->map_orig[x][y] = 'F';
	flood_fill_algo(cub, limit + 1, x + 1, y);
	flood_fill_algo(cub, limit + 1, x - 1, y);
	flood_fill_algo(cub, limit + 1, x, y + 1);
	flood_fill_algo(cub, limit + 1, x, y - 1);
}

void	scan_errors(t_cub *cub, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("01NSWE ", map[i][j]) == 0)
				ft_stop(EXIT_FAILURE, cub, "Error\nUnallowed character in map");
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (cub->sp_dir != '!')
					ft_stop(EXIT_FAILURE, cub, "Error\nCant have spawns > 1");
				cub->sp_dir = cub->map_orig[i][j];
				cub->spawnx = i;
				cub->spawny = j;
			}
			j++;
		}
		i++;
	}
	if (cub->sp_dir == '!')
		ft_stop(EXIT_FAILURE, cub, "Error\nMust have a spawn position");
}

void	find_max(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map_orig[i])
	{
		j = 0;
		while (cub->map_orig[i][j])
			j++;
		if (cub->width < j)
			cub->width = j;
		i++;
	}
	cub->height = i;
}

void	check_map(t_cub *cub, char *map)
{
	int	i;
	int	j;

	i = 0;
	check_consecutive_nl(cub, map);
	cub->map_orig = ft_split(map, '\n');
	if (cub->map_orig == NULL)
		ft_stop(1, cub, "Error\nft_split failed");
	find_max(cub);
	scan_errors(cub, cub->map_orig);
	cub->map_orig[cub->spawnx][cub->spawny] = '0';
	flood_fill_algo(cub, 0, cub->spawnx, cub->spawny);
	while (cub->map_orig[i])
	{
		j = 0;
		while (cub->map_orig[i][j])
		{
			if (cub->map_orig[i][j] == '0')
				flood_fill_algo(cub, 0, i, j);
			j++;
		}
		i++;
	}
}
