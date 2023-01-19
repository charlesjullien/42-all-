/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pos_d_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:11:26 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:11:28 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_d2(t_data *data)
{
	if (data->pa >= P2 && data->pa < PI + 0.000001)
	{
		if (data->map[data->iposx_sub_wxo][data->iposy] == '0')
			data->posx -= cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_add_wyo] == '0')
			data->posy -= sin(data->pa + PI / 2) * 3;
	}
	else if (data->pa >= PI + 0.000001 && data->pa < P3 + 0.000001)
	{
		if (data->map[data->iposx_add_wxo][data->iposy] == '0')
			data->posx -= cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_sub_wyo] == '0')
			data->posy -= sin(data->pa + PI / 2) * 3;
	}
}

void	move_player_d(t_data *data)
{
	if ((data->pa >= P3 + 0.000001 && data->pa < PI * 2) || data->pa == 0)
	{
		if (data->map[data->iposx_sub_wxo][data->iposy] == '0')
			data->posx -= cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_add_wyo] == '0')
			data->posy -= sin(data->pa + PI / 2) * 3;
	}
	else if (data->pa >= 0.0 && data->pa < P2 + 0.000001)
	{
		if (data->map[data->iposx_add_wxo][data->iposy] == '0')
			data->posx -= cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_sub_wyo] == '0')
			data->posy -= sin(data->pa + PI / 2) * 3;
	}
	else
		move_player_d2(data);
}

void	move_player_a2(t_data *data)
{
	if (data->pa >= P2 && data->pa < PI + 0.000001)
	{
		if (data->map[data->iposx_add_wxo][data->iposy] == '0')
			data->posx += cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_sub_wyo] == '0')
			data->posy += sin(data->pa + PI / 2) * 3;
	}
	else if (data->pa >= PI + 0.000001 && data->pa < P3 + 0.000001)
	{
		if (data->map[data->iposx_sub_wxo][data->iposy] == '0')
			data->posx += cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_add_wyo] == '0')
			data->posy += sin(data->pa + PI / 2) * 3;
	}
}

void	move_player_a(t_data *data)
{
	if ((data->pa >= P3 + 0.000001 && data->pa < PI * 2) || data->pa == 0)
	{
		if (data->map[data->iposx_add_wxo][data->iposy] == '0')
			data->posx += cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_sub_wyo] == '0')
			data->posy += sin(data->pa + PI / 2) * 3;
	}
	else if (data->pa >= 0.0 && data->pa < P2 + 0.000001)
	{
		if (data->map[data->iposx_sub_wxo][data->iposy] == '0')
			data->posx += cos(data->pa + PI / 2) * 3;
		if (data->map[data->iposx][data->iposy_add_wyo] == '0')
			data->posy += sin(data->pa + PI / 2) * 3;
	}
	else
		move_player_a2(data);
}
