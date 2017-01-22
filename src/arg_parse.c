/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:12:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/19 09:10:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		handle_env_(char *arg, const char *cmd, size_t *a, size_t *c)
{
	char	*env;

	*c += 1;
	env = arg_env(cmd + *c);
	ft_strcpy(arg + *a, env);
	*a += ft_strlen(env);
	while (NOT_ENVDELIM(cmd[*c]))
		*c += 1;
}

static void		handle_qenv_(char *arg, const char *cmd, size_t *a, size_t *c)
{
	char	*env;

	*c += 1;
	env = arg_env(cmd + *c);
	ft_strcpy(arg + *a, env);
	*a += ft_strlen(env);
	while (NOT_ENVDELIM(cmd[*c]))
		*c += 1;
	*c -= 1;
}

static void		handle_quote_(char *arg, const char *cmd, size_t *a, size_t *c)
{
	char	end_quote;

	end_quote = cmd[*c];
	while (cmd[*c += 1] != 0 && cmd[*c] != end_quote)
		if (cmd[*c] == '$' && end_quote != '\'')
			handle_qenv_(arg, cmd, a, c);
		else
			arg[(*a)++] = cmd[*c];
	if (cmd[*c] == end_quote)
		*c += 1;
}

char			*arg_parse(const char *cmd)
{
	char	*arg;
	size_t	a;
	size_t	c;

	a = 0;
	c = 0;
	MGUARD(arg = (char*)malloc(arg_len(cmd) + 1));
	while (cmd[c] != 0 && !ft_isspace(cmd[c]))
	{
		if (cmd[c] == '$')
			handle_env_(arg, cmd, &a, &c);
		if (IS_QUOTE(cmd[c]))
			handle_quote_(arg, cmd, &a, &c);
		while (NOT_ASDELIM(cmd[c]))
			arg[a++] = cmd[c++];
	}
	arg[a] = 0;
	return (arg);
}
