/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:22:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/19 09:10:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		handle_env_(const char *cmd, size_t *c, size_t *l)
{
	*c += 1;
	*l += ft_strlen(arg_env(cmd + *c));
	while (NOT_ENVDELIM(cmd[*c]))
		*c += 1;
}

static void		handle_quoted_env(const char *cmd, size_t *c, size_t *l)
{
	*c += 1;
	*l += ft_strlen(arg_env(cmd + *c));
	while (NOT_ENVDELIM(cmd[*c]))
		*c += 1;
	*c -= 1;
}

static void		handle_quote_(const char *cmd, size_t *c, size_t *l)
{
	char	end_quote;

	end_quote = cmd[*c];
	while (cmd[*c += 1] != 0 && cmd[*c] != end_quote)
	{
		if (cmd[*c] == '$' && end_quote != '\'')
			handle_quoted_env(cmd, c, l);
		else
			*l += 1;
	}
	if (cmd[*c] == end_quote)
		*c += 1;
}

size_t			arg_len(const char *cmd)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (cmd[i] != 0 && !ft_isspace(cmd[i]))
	{
		if (cmd[i] == '$')
			handle_env_(cmd, &i, &l);
		if (IS_QUOTE(cmd[i]))
			handle_quote_(cmd, &i, &l);
		while (NOT_ASDELIM(cmd[i]))
		{
			i += 1;
			l += 1;
		}
	}
	return (l);
}
