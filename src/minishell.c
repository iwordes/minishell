/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:51:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 18:54:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	minishell(void)
{
	char	*input;
	char	**cmd;
	char	**argv;
	size_t	i;

	while (1)
	{
		cmd_prompt();
		if (ft_readln(0, &input) <= 0)
			break ;
		i = 0;
		cmd = cmd_split(input);
		while (cmd[i] != NULL)
		{
			argv = cmd_parse(cmd[i]);
			sub_home(argv);
			if (argv[0] != NULL)
				cmd_exec(argv);
			destroy_argv(argv);
			i += 1;
		}
		destroy_cmd(cmd);
		free(input);
	}
	write(1, "exit\n", 5);
}
