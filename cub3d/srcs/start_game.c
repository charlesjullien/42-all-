/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <mabuchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:09:54 by mabuchar          #+#    #+#             */
/*   Updated: 2022/02/20 17:10:00 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	rgbtohex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

float	dir_pos(t_cub *cub)
{
	if (cub->sp_dir == 'N')
		return (PI);
	if (cub->sp_dir == 'S')
		return (0);
	if (cub->sp_dir == 'W')
		return (P3);
	if (cub->sp_dir == 'E')
		return (P2);
	return (0);
}

void	data_init(t_data *data, t_cub *cub)
{
	data->colorc = rgbtohex(cub->ceiling[0], cub->ceiling[1], cub->ceiling[2]);
	data->colorf = rgbtohex(cub->floor[0], cub->floor[1], cub->floor[2]);
	data->w = 0;
	data->a = 0;
	data->s = 0;
	data->d = 0;
	data->gau = 0;
	data->dro = 0;
	data->disth = -1;
	data->distv = -1;
	data->mh = WIN_H;
	data->ml = WIN_L;
	data->mapx = cub->width;
	data->mapy = cub->height;
	data->resx = 64;
	data->resy = 64;
	data->posx = 32 + cub->spawnx * data->resx;
	data->posy = 32 + cub->spawny * data->resy;
	data->pa = dir_pos(cub);
	data->pdx = sin(data->pa) * 2;
	data->pdy = cos(data->pa) * 2;
}

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data->cub, 0);
	exit(0);
	return (1);
}

void	start_game(t_cub *cub)
{
	t_data	data;

	data.cub = cub;
	data.so = cub->south;
	data.no = cub->north;
	data.we = cub->west;
	data.ea = cub->east;
	data.map = cub->map;
	data_init(&data, cub);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.ml, data.mh, "cub3D");
	data.img = mlx_new_image(data.mlx, data.ml, data.mh);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixels,
			&data.line_length, &data.endian);
	load_texture(&data);
	draw_rays3d(&data);
	draw_map_2d(&data, data.map);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, &hook_pressed, &data);
	mlx_hook(data.win, 3, 1L << 1, &hook_released, &data);
	mlx_hook(data.win, 33, 1L << 17, &ft_exit, &data);
	mlx_loop_hook(data.mlx, &next_frame, &data);
	mlx_loop(data.mlx);
}
