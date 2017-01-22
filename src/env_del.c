/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:37:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 11:11:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Return true if the key was found and deleted.
** Return false if the key was not found.
*/

char	env_del(const char *key)
{
	size_t	i;

	i = ~0;
	while (g_env.env[i += 1] != NULL)
		if (env_cmp(key, g_env.env[i]))
		{
			free(g_env.env[i]);
			while (g_env.env[i += 1] != NULL)
				g_env.env[i - 1] = g_env.env[i];
			g_env.env[i - 1] = NULL;
			return (1);
		}
	return (0);
}
