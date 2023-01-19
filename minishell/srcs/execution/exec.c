/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:24:05 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 17:00:30 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_access(t_cmd *lex)
{
	char	*path;

	path = NULL;
	path = ft_get_path(lex[0].tab);
	if (path != NULL)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

char	**get_arg(t_cmd *lex, const int x, int *i)
{
	char	**tmp;
	int		j;

	if (*i >= x)
		return (NULL);
	tmp = malloc(sizeof(char *) * (x + 1));
	if (tmp == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	j = 0;
	while (*i < x && !parse_builtin2(lex, *i))
	{
		lex[*i].tab = check_variable(lex[*i].tab, 0);
		tmp[j] = ft_strdup(lex[*i].tab);
		j++;
		*i = *i + 1;
	}
	tmp[j] = NULL;
	return (tmp);
}

void	return_child(void)
{
	if (WIFEXITED(g_global.pid))
		g_global.last_ret = WEXITSTATUS(g_global.pid);
	if (WIFSIGNALED(g_global.pid))
	{
		g_global.last_ret = WTERMSIG(g_global.pid);
		if (g_global.last_ret != 131)
			g_global.last_ret += 128;
	}
}

int	exec_cmd(t_cmd *lex, int *fd, int *i)
{
	char	**arg;
	char	*path;

	arg = get_arg(lex, lex[0].x, i);
	path = ft_get_path(arg[0]);
	if (path)
		run_cmd(arg, path, lex, fd);
	return (0);
}

int	run_cmd(char **arg, char *path, t_cmd *lex, int *fd)
{
	g_global.pid = fork();
	if (g_global.pid < 0)
	{
		free_strs(NULL, path);
		ft_putstr_fd("minishell: execve: failed to create a new process.\n", 2);
		g_global.last_ret = 1;
		return (-1);
	}
	if (!g_global.pid)
	{
		pip_redir(lex, fd, 0, 0);
		execve(path, arg, g_global.env);
	}
	free(path);
	if (ft_strequ(arg[0], "./minishell"))
		signal(SIGINT, SIG_IGN);
	wait(&g_global.pid);
	return_child();
	g_global.pid = 0;
	return (1);
}
