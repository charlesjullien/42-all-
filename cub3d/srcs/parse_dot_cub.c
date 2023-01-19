/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dot_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:07:47 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/16 10:18:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pass_spaces(t_cub *cub, char *str, int *i)
{
	int	coma;

	coma = 0;
	while (str[*i] == ',' || str[*i] == ' ')
	{
		if (str[*i] == ',')
			coma++;
		*i += 1;
	}
	if (coma != 1)
		ft_stop(EXIT_FAILURE, cub, "Error\nIssue in C or F RGB infos.");
}

void	get_colors(t_cub *cub, int *tab, int i, int j)
{
	while (ft_isalpha(cub->line[i]))
		i++;
	if (i != 1)
		ft_stop(EXIT_FAILURE, cub, "Error\nIssue in C or F RGB infos.");
	while (cub->line[i] == ' ')
		i++;
	while (j < 3)
	{
		tab[j] = ft_atoi(&cub->line[i]);
		while (ft_isdigit(cub->line[i]))
			i++;
		if (j != 2)
			pass_spaces(cub, cub->line, &i);
		else if (j == 2)
		{
			while (cub->line[i] == ' ')
				i++;
			if (cub->line[i] != '\0')
				ft_stop(EXIT_FAILURE, cub, "Error\nIssue in C or F RGB infos.");
		}
		j++;
	}
}

void	find_texture(t_cub *cub, char **str)
{
	int	i;

	i = 0;
	while (ft_isalpha(cub->line[i]) && i < 2)
		i++;
	while (cub->line[i] == ' ')
		i++;
	*str = ft_strdup(&cub->line[i]);
	if (i < 2 || i == 0 || !*str)
		ft_stop(EXIT_FAILURE, cub, "Error\nIssue in textures infos");
}

void	get_elements(t_cub *cub)
{
	if (ft_strnstr(cub->line, "NO", 2) && !cub->north)
		find_texture(cub, &cub->north);
	else if (ft_strnstr(cub->line, "SO", 2) && !cub->south)
		find_texture(cub, &cub->south);
	else if (ft_strnstr(cub->line, "WE", 2) && !cub->west)
		find_texture(cub, &cub->west);
	else if (ft_strnstr(cub->line, "EA", 2) && !cub->east)
		find_texture(cub, &cub->east);
	else if (ft_strnstr(cub->line, "F", 1) && cub->floor[0] == -1)
		get_colors(cub, cub->floor, 0, 0);
	else if (ft_strnstr(cub->line, "C", 1) && cub->ceiling[0] == -1)
		get_colors(cub, cub->ceiling, 0, 0);
	else
		ft_stop(EXIT_FAILURE, cub, "Error\nWrong elements orga in .cub");
}

void	parse_dot_cub(char *map, t_cub *cub)
{
	int	j;
	int	elements;

	elements = 0;
	j = 0;
	fill_from_dot_cub(cub, map);
	while (cub->dot_cub[j] == '\n')
		j++;
	while (elements < 6)
	{
		if (mini_gnl(&cub->dot_cub[j], cub, &j, 0) == 0 && elements < 6)
			ft_stop(EXIT_FAILURE, cub, "Error\nWrong orga in .cub file");
		if (cub->line)
		{
			get_elements(cub);
			elements++;
		}
	}
	check_map(cub, &cub->dot_cub[j]);
}
