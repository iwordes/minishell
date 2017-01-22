/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:36:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 10:33:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Return 0 if no environment variable was created.
** Return 1 if an existing environment variable was overwritten.
** Return 2 if a new environment variable was created.
*/

char	env_set(const char *envar)
{
	char	cmp;
	size_t	i;

	i = ~0;
	if (envar[0] == 0)
		return (0);
	while (g_env.env[i += 1] != NULL)
		if ((cmp = env_cmp(envar, g_env.env[i])) != 0)
		{
			if (cmp == 2)
				return (1);
			free(g_env.env[i]);
			MGUARD(g_env.env[i] = ft_strdup(envar));
			return (1);
		}
	env_new(envar);
	return (2);
}
