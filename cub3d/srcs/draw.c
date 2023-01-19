/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:10:53 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:10:55 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_we(t_data *data)
{
	data->wall_index = data->colorw;
	if (data->wall_index == 0 || data->wall_index == 1)
	{
		data->pos_tex = 0;
		data->j = 0;
		while (data->j < data->rx)
			data->j += 64;
		data->pos_tex = data->rx - (data->j - 64);
		data->pos_tex = (data->pos_tex - 64) * -1;
	}
	if (data->wall_index == 2 || data->wall_index == 3)
	{
		data->pos_tex = 0;
		data->j = 0;
		while (data->j < data->ry)
			data->j += 64;
		data->pos_tex = data->ry - (data->j - 64);
		data->pos_tex = (data->pos_tex - 64) * -1;
	}
}

void	draw_floor(t_data *data)
{
	if (data->lineh >= data->mh)
		return ;
	while (data->dx < data->mh)
	{
		data->dy = 0;
		while (data->dy < data->ml / WIN_L)
		{
			my_mlx_pixel_put(data, data->li + data->dy, data->dx, data->colorf);
			data->dy++;
		}
		data->dx++;
	}
}

void	draw_ceiling(t_data *data)
{
	if (data->lineh >= data->mh)
	{
		data->loff = (data->lineh - data->mh) / 2;
		while (data->chl < data->loff)
		{
			data->pos_tex += 64;
			data->chl += data->ch;
		}
		data->lineh = data->mh;
		data->dx = 0;
	}
	data->li = data->r * (data->ml / WIN_L);
	data->di = 0;
	while (data->di < data->dx)
	{
		data->dy = 0;
		while (data->dy < data->ml / WIN_L)
		{
			my_mlx_pixel_put(data, data->li + data->dy, data->di, data->colorc);
			data->dy++;
		}
		data->di++;
	}
}

void	draw_init(t_data *data)
{
	data->ca = data->pa - data->ra;
	if (data->ca < 0)
		data->ca += 2 * PI;
	if (data->ca > 2 * PI)
		data->ca -= 2 * PI;
	draw_we(data);
	data->loff = 0;
		data->distt = data->distt * cos(data->ca);
	data->lineh = (data->resx * data->mh) / data->distt;
	data->dx = ((data->mh / 2) - data->lineh / 2);
	data->chl = data->lineh / 64;
	data->ch = data->chl;
	draw_ceiling(data);
	if (data->lineh < data->mh)
		data->di = 0;
	else
		data->di = data->loff;
}

void	draw_3d(t_data *data)
{
	draw_init(data);
	while (data->di < data->lineh + data->loff)
	{
		data->dy = 0;
		while (data->dy < data->ml / WIN_L)
		{
			my_mlx_pixel_put(data, data->li + data->dy, data->dx,
				data->tex[data->wall_index][data->pos_tex]);
			data->dy++;
		}
		data->di++;
		data->dx++;
		if (data->di > data->chl)
		{
			while (data->chl < data->di)
			{
				data->pos_tex += 64;
				data->chl += data->ch;
			}
		}
	}
	draw_floor(data);
}
