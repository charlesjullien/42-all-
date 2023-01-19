/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:17:03 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 17:03:20 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	change_directory(char *dest, char *path)
{
	char	*env_var_value;
	char	*pwd_save;
	int		check;

	env_var_value = get_var_value(dest);
	pwd_save = get_pwd();
	check = check_if_reachable(env_var_value, pwd_save, path);
	if (pwd_save)
		free(pwd_save);
	return (check);
}

int	check_if_reachable(char *dest, char *pwd_save, char *path)
{
	struct stat		buf;
	char			*pwd;
	int				status;

	if (chdir(dest) == -1)
	{
		chdir(pwd_save);
		status = stat(path, &buf);
		if (status == -1)
			ft_error(path, ": No such file or directory\n", 2, 127);
		else if (status == 0)
			ft_error(NULL, ": Not a directory\n", 2, 1);
		else
			return (1);
	}
	pwd = get_pwd();
	redefine_env("PWD", pwd, 0, 0);
	redefine_env("OLDPWD", pwd_save, 0, 0);
	if (pwd)
		free(pwd);
	return (0);
}

int	check_path_more(int fd, char *path)
{
	write(fd, get_var_value("OLDPWD"), ft_strlen(get_var_value("OLDPWD")));
	write(fd, "\n", 1);
	change_directory("OLDPWD", path);
	return (1);
}

int	check_path(char *path, int fd)
{
	char	*pwd;
	int		check;

	if (ft_strcmp(get_var_value("OLDPWD"), "OLDPWD", 7)
		== 0 && path && path[0] == '-')
	{
		ft_error("cd :", "OLDPWD not set\n", fd, 1);
		return (0);
	}
	check = 0;
	pwd = get_pwd();
	if (count_c_in_str(path, '/') == ft_strlen(path))
	{
		check_if_reachable("/", pwd, path);
		check = 1;
	}
	else if (path && path[0] == '-' && ft_strlen(path) == 1)
		check = check_path_more(fd, path);
	if (pwd)
		free(pwd);
	if (check)
		return (0);
	return (1);
}

void	execute_cd(char *path, int fd)
{
	char	**splitted;
	char	*pwd_save;
	int		i;

	i = -1;
	pwd_save = get_pwd();
	if (!check_path(path, fd))
		return ;
	splitted = ft_split(path, '/');
	if (!splitted)
		change_directory("HOME", path);
	while (splitted[++i])
	{
		if (i == 0 && path[0] == '/')
			splitted[0] = ft_strjoin("/", splitted[0]);
		if (change_directory(splitted[i], path))
			break ;
		else
			g_global.last_ret = 0;
	}
	if (ft_strcmp(pwd_save, get_pwd(), (ft_strlen(pwd_save) + 30)))
		redefine_env("OLDPWD", pwd_save, 0, 0);
	if (pwd_save)
		free(pwd_save);
}
