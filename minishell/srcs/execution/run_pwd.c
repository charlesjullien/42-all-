/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:22:46 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:23:51 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_pwd(int fd)
{
	char	buf[4096];

	g_global.last_ret = 0;
	getcwd(buf, 4096);
	write(fd, buf, ft_strlen(buf));
	write(fd, "\n", 1);
}
