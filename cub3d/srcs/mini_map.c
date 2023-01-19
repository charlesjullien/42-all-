/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:10:30 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:10:32 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	find_div(t_data *data)
{
	float	i;

	i = 0.0;
	if (data->mapx > data->mapy)
		i = data->mapx + 1;
	else
		i = data->mapy + 1;
	data->div = (float)data->resx * (float)i / 150.0;
}

void	put_player(t_data *data, int x, int y)
{
	int		i;
	int		j;
	float	k;

	i = 0;
	while (i <= 2)
	{
		j = 0;
		while (j <= 2)
		{
			my_mlx_pixel_put(data, y + i, x + j, 0x00FFFF00);
			j++;
		}
		i++;
	}
	k = 0;
	while (k < 5)
	{
		if ((x + data->pdy * k) >= 0 && (y + data->pdx * k) >= 0)
			my_mlx_pixel_put(data, (y + data->pdx * k),
				(x + data->pdy * k), 0x00FFFF00);
		k += 0.1;
	}
}

void	draw_map_2d2(t_data *data, int x, int y, int color)
{
	float	i;
	float	j;

	i = 0;
	while (i <= (float)data->resx / data->div)
	{
		j = 0;
		while (j <= (float)data->resy / data->div)
		{
			my_mlx_pixel_put(data, (x * data->resx / data->div) + i,
				(y * data->resy / data->div) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	find_div(data);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] && x < 500)
		{
			if (map[y][x] == '1')
				draw_map_2d2(data, x, y, 0x00FF0000);
			if (map[y][x] == '0')
				draw_map_2d2(data, x, y, 0x00FF8888);
			x++;
		}
		y++;
	}
	put_player(data, data->posx / data->div, data->posy / data->div);
}
