/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:29:02 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 12:34:40 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_cmd *lex, char *str)
{
	if (str)
		printf("%s", str);
	if (g_global.env)
		free_env();
	if (g_global.hist)
		free_hist();
	if (lex != NULL)
		free_lex(lex);
	exit(g_global.last_ret);
}

void	ascii_art(void)
{
	ft_putstr_fd("\033[1;34m        _       _     _          _ _ \n", 1);
	ft_putstr_fd("  /\\/\\ (_)_ __ (_)___| |__   ___| | |\n", 1);
	ft_putstr_fd(" /    \\| | '_ \\| / __| '_ \\ / _ \\ | |\n", 1);
	ft_putstr_fd("/ /\\/\\ \\ | | | | \\__ \\ | | |  __/ | |\n", 1);
	ft_putstr_fd("\\/    \\/_|_| |_|_|___/_| |_|\\___|_|_|\033[0m\n\n\n", 1);
}

int	main(int argc, char **argv, char **env)
{
	size_t	i;

	i = 0;
	(void)argc;
	(void)argv;
	while (env[i])
		i++;
	g_global.env = malloc(sizeof(char *) * (i + 1));
	if (g_global.env == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = -1;
	while (env[++i])
		g_global.env[i] = ft_strdup(env[i]);
	g_global.env[i] = 0;
	ascii_art();
	reading();
	return (0);
}
