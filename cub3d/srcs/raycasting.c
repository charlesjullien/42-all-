/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:10:16 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:10:18 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_dist_ray(t_data *data)
{
	data->rpdx = cos(data->ra) * 2;
	data->rpdy = sin(data->ra) * 2;
	data->hx = data->posx;
	data->hy = data->posy;
		data->disth = draw_rays_hor3d(data);
		data->distv = draw_rays_ver3d(data);
	if ((data->distv >= 0 && data->distv < data->disth) || data->disth < 0)
		data->distt = data->distv;
	else if ((data->disth >= 0 && data->disth < data->distv) || data->distv < 0)
	{
		draw_rays_hor3d(data);
		data->distt = data->disth;
	}
}

void	init_ra(t_data *data, int i)
{
	if (i == 0)
		data->ra = data->pa + DR * 30;
	else if (i == 1)
		data->ra -= (DR * 60) / WIN_L;
	if (data->ra < 0)
		data->ra += 2 * PI;
	if (data->ra > 2 * PI)
		data->ra -= 2 * PI;
}

void	draw_rays3d(t_data *data)
{
	init_ra(data, 0);
	data->r = 0;
	while (data->r < WIN_L)
	{
		get_dist_ray(data);
		draw_3d(data);
		data->r++;
		init_ra(data, 1);
	}
}
