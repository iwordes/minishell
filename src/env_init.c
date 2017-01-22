/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:35:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 10:37:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Duplicate the current environment to a global variable.
*/

void		env_init(void)
{
	extern char	**environ;
	size_t		i;
	size_t		l;

	l = 0;
	while (environ[l] != NULL)
		l += 1;
	g_env.len = 2;
	while (g_env.len < l)
		g_env.len *= 2;
	if ((g_env.env = (char**)malloc(sizeof(void*) * (g_env.len + 1))) == NULL)
	{
		ft_putstr("minishell: Insufficient memory to duplicate parent ENV.\n");
		exit(ENOMEM);
	}
	i = ~0;
	while ((i += 1) < l)
		MGUARD(g_env.env[i] = ft_strdup(environ[i]));
	g_env.env[i] = NULL;
	g_env.env[g_env.len] = NULL;
	;
	env_set("SHELL=minishell");
	env_set("PROMPT=> ");
}
