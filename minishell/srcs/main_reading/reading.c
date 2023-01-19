/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:53 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:48:38 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_to_history_more(char **tmp, int *i, char *str)
{
	tmp = malloc(sizeof(char *) * (*i + 2));
	if (tmp == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	*i = 0;
	while (g_global.hist[*i] != NULL)
	{
		tmp[*i] = ft_strdup(g_global.hist[*i]);
		*i = *i + 1;
	}
	tmp[*i] = ft_strdup(str);
	*i = *i + 1;
	tmp[*i] = NULL;
	free_hist();
	g_global.hist = tmp;
}

void	add_to_history(char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (g_global.hist)
	{
		while (g_global.hist[i] != NULL)
			i++;
	}
	if (i == 0)
	{
		tmp = malloc(sizeof(char *) * 2);
		if (tmp == NULL)
			ft_exit(NULL, "Warning : Malloc failed\n");
		tmp[0] = ft_strdup(str);
		tmp[1] = NULL;
		g_global.hist = tmp;
	}
	else if (i > 0)
		add_to_history_more(tmp, &i, str);
}

void	prompt(void)
{
	char	*tmp;
	size_t	len;
	size_t	count_slash;

	tmp = getenv("USER");
	if (tmp)
	{
		ft_putstr_fd("\033[32;1m", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("@\033[0m:", 1);
	}
	tmp = getcwd(NULL, 0);
	len = ft_strlen(tmp);
	count_slash = 0;
	while (--len && count_slash < 3)
		if (tmp[len] == '/')
			count_slash++;
	ft_putstr_fd("\e[1;34m", 1);
	while (tmp[++len])
		ft_putchar_fd(tmp[len], 1);
	ft_putstr_fd("$\e[0m ", 1);
	free(tmp);
}

static void	init(void)
{
	size_t	i;
	char	*tmp;

	tmp = getenv("SHLVL");
	i = (ft_atoi(tmp) + 1);
	tmp = ft_itoa(i);
	set_env("SHLVL", tmp);
	free(tmp);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	g_global.pid = 0;
	g_global.last_ret = 0;
	prompt();
}

int	reading(void)
{
	char	*line;

	init();
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		signal(SIGINT, signal_handler);
		if (ft_strlen(line))
			add_to_history(line);
		if (ft_strlen(line))
			lexing(line, 0);
		free(line);
		prompt();
	}
	ft_putstr_fd("exit\n", 1);
	free_env();
	if (g_global.hist)
		free_hist();
	return (0);
}
