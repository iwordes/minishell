/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:12:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 14:21:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Return a pointer to the value associated with key.
** Return NULL if the key was not found.
*/

char	*env_get(const char *key)
{
	size_t	i;
	size_t	j;

	i = ~0;
	while (g_env.env[i += 1] != NULL)
	{
		j = 0;
		while (key[j] != 0 && key[j] == g_env.env[i][j])
			j += 1;
		if (key[j] == 0 && g_env.env[i][j] == '=')
			return (g_env.env[i] + j + 1);
	}
	return (NULL);
}
