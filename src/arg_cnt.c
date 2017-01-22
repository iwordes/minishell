/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:13:30 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 19:16:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	arg_cnt(const char *cmd)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	while (cmd[i] != 0)
	{
		while (ft_isspace(cmd[i]))
			i += 1;
		if (cmd[i] != 0)
			a += 1;
		i += arg_next(cmd + i);
	}
	return (a);
}
