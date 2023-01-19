/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:21:40 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 16:22:55 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error(char *s2, char *s3, int fd, int rv)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
	g_global.last_ret = rv;
}
