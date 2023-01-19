/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dot_cub_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:14 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/17 14:40:15 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	refill_map_2(t_cub *cub, int i, int j)
{
	while (i < cub->height)
	{
		j = 0;
		while (j < cub->width)
		{
			cub->map[i][j] = '1';
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < cub->height)
	{
		j = 0;
		while (j < ft_strlen(cub->map_orig[i]))
		{
			if (cub->map_orig[i][j] != ' ')
				cub->map[i][j] = cub->map_orig[i][j];
			j++;
		}
		i++;
	}
}

void	refill_map(t_cub *cub, int i)
{
	cub->map = malloc(sizeof(char *) * (cub->height + 1));
	if (!cub->map)
		ft_stop(EXIT_FAILURE, cub, "Error\nMalloc failed.");
	cub->map[cub->height] = NULL;
	while (i < cub->height)
	{
		cub->map[i] = malloc(sizeof(char) * (cub->width + 1));
		if (!cub->map[i])
			ft_stop(EXIT_FAILURE, cub, "Error\nMalloc failed.");
		cub->map[i][cub->width] = '\0';
		i++;
	}
	refill_map_2(cub, 0, 0);
}

void	reset_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map_orig[i])
	{
		j = 0;
		while (cub->map_orig[i][j])
		{
			if (cub->map_orig[i][j] == 'F')
				cub->map_orig[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	parse_dot_cub_2(t_cub *cub)
{
	if (cub->floor[0] < 0 || cub->floor[0] > 255
		|| cub->floor[1] < 0 || cub->floor[1] > 255
		|| cub->floor[2] < 0 || cub->floor[2] > 255)
		ft_stop(EXIT_FAILURE, cub, "Error\nF RGB must be >= 0 || <= 255");
	if (cub->ceiling[0] < 0 || cub->ceiling[0] > 255
		|| cub->ceiling[1] < 0 || cub->ceiling[1] > 255
		|| cub->ceiling[2] < 0 || cub->ceiling[2] > 255)
		ft_stop(EXIT_FAILURE, cub, "Error\nC RGB must be >= 0 || <= 255");
	reset_map(cub);
}
