/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:56:28 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 17:04:12 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_n(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i] && (str[i] == '-' || str[i] == 'n' || str[i] == ' '))
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == 'n')
		{
			i++;
			while (str[i] && str[i] == 'n')
				i++;
			if (str[i] && str[i] == ' ')
				index = 1;
		}
		i++;
	}
	return (index);
}

char	*reset_newline_more(char *str, int *i)
{
	char	*tmp;

	while (*i > 0 && str[*i] != '-')
		*i = *i - 1;
	tmp = ft_strdup(&str[*i]);
	free(str);
	return (tmp);
}

char	*reset_newline(char *str, int i)
{
	char	*tmp;

	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == 'n')
		{
			i++;
			while (str[i] == 'n')
				i++;
			if (!str[i])
				return (NULL);
			if (str[i - 1] == 'n' && str[i] && str[i] != ' ')
				return (reset_newline_more(str, &i));
			if (str[i] && str[i] != 'n' && str[i + 1] && str[i + 1] != '-')
			{
				tmp = ft_strdup(&str[i + 1]);
				free(str);
				return (tmp);
			}
		}
		i++;
	}
	return (str);
}

void	execute_echo(char *str, int fd)
{
	int	i;
	int	n;

	g_global.last_ret = 0;
	i = 0;
	n = find_n(str);
	if (!str && !n)
	{
		write(fd, "\n", 1);
		return ;
	}
	str = reset_newline(str, 0);
	if (str)
		write(fd, str, ft_strlen(str));
	if (!n)
		write(fd, "\n", 1);
	free(str);
}
