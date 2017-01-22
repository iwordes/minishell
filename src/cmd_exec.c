/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/21 19:35:22 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char		*g_builtins[] =
{
	"banana",
	"cd",
	"echo",
	"env",
	"exit",
	"help",
	"setenv",
	"unsetenv",
	NULL
};

static int		(*g_builtin[])(char**) =
{
	bi_nanners,
	bi_cd,
	bi_echo,
	bi_env,
	bi_exit,
	bi_help,
	bi_setenv,
	bi_unsetenv
};

static int		finish(int status)
{
	char	*s;

	MGUARD(s = ft_itoa(status));
	env_setkey("?", s);
	free(s);
	return (status);
}

int				cmd_exec(char **argv)
{
	size_t	i;

	if (ft_strchr(argv[0], '/') != NULL)
		return (finish(exec_path(argv[0], argv)));
	i = ~0;
	while (g_builtins[i += 1] != NULL)
		if (ft_striequ(g_builtins[i], argv[0]))
			return (finish(g_builtin[i](argv)));
	return (finish(exec_name(argv[0], argv)));
}
