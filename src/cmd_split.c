/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:49:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 19:01:22 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Accurately split a command by ';'.
*/

char	**cmd_split(const char *input)
{
	char	**cmd;
	size_t	c;
	size_t	i;
	size_t	l;

	c = 0;
	i = 0;
	MGUARD(cmd = (char**)malloc(sizeof(void*) * (cmd_cnt(input) + 1)));
	while (input[i] != 0)
	{
		ITER(i, ft_isspace(input[i]));
		ITER(i, input[i] == ';');
		if (input[i] == 0 || ft_isspace(input[i]))
			continue ;
		l = cmd_next(input + i);
		cmd[c++] = ft_strsub(input, i, l);
		i += l;
	}
	cmd[c] = NULL;
	return (cmd);
}
