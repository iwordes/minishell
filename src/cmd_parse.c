/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:07:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 19:16:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char		**cmd_parse(const char *cmd)
{
	char	**argv;
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	MGUARD(argv = (char**)malloc(sizeof(void*) * (arg_cnt(cmd) + 1)));
	while (cmd[i] != 0)
	{
		while (ft_isspace(cmd[i]))
			i += 1;
		if (cmd[i] != 0)
			argv[a++] = arg_parse(cmd + i);
		i += arg_next(cmd + i);
	}
	argv[a] = NULL;
	return (argv);
}
