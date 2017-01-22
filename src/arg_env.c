/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:22:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/19 09:21:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Parse the given command-string for a key to lookup in ENV.
** Return the value of key, or "" if the key was not found.
*/

char	*arg_env(const char *cmd)
{
	char	*env;
	char	*key;
	size_t	l;

	l = 0;
	while (NOT_ENVDELIM(cmd[l]))
		l += 1;
	if (l == 0)
		return ("$");
	MGUARD(key = ft_strsub(cmd, 0, l));
	env = env_get_safe(key);
	free(key);
	return (env);
}
