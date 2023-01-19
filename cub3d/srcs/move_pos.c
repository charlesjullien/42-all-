/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:11:38 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:11:39 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pos_wall(t_data *data)
{
	data->wxo = 0;
	data->wyo = 0;
	if (data->pdx > 0)
		data->wyo = 20;
	else
		data->wyo = -20;
	if (data->pdy > 0)
		data->wxo = 20;
	else
		data->wxo = -20;
	data->iposx = data->posx / data->resx;
	data->iposy = data->posy / data->resy;
	data->iposx_add_wxo = (data->posx + data->wxo) / data->resx;
	data->iposy_add_wyo = (data->posy + data->wyo) / data->resy;
	data->iposx_sub_wxo = (data->posx - data->wxo) / data->resx;
	data->iposy_sub_wyo = (data->posy - data->wyo) / data->resy;
}

void	move_player2(t_data *data)
{
	if (data->d == 1)
		move_player_d(data);
	else if (data->gau == 1)
	{
		data->pa += 0.05;
		if (data->pa > (2 * PI))
			data->pa -= 2 * PI;
		data->pdx = sin(data->pa) * 2;
		data->pdy = cos(data->pa) * 2;
	}
	else if (data->dro == 1)
	{
		data->pa -= 0.05;
		if (data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = sin(data->pa) * 2;
		data->pdy = cos(data->pa) * 2;
	}
}

void	move_player(t_data *data)
{
	pos_wall(data);
	if (data->w == 1)
	{
		if (data->map[data->iposx_add_wxo][data->iposy] == '0')
			data->posx += data->pdy * 3;
		if (data->map[data->iposx][data->iposy_add_wyo] == '0')
			data->posy += data->pdx * 3;
	}
	else if (data->s == 1)
	{
		if (data->map[data->iposx_sub_wxo][data->iposy] == '0')
			data->posx -= data->pdy * 3;
		if (data->map[data->iposx][data->iposy_sub_wyo] == '0')
			data->posy -= data->pdx * 3;
	}
	else if (data->a == 1)
		move_player_a(data);
	else
		move_player2(data);
}
