/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:02:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/12 16:11:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	env_new(const char *envar)
{
	size_t	e;
	size_t	i;

	e = ~0;
	while (g_env.env[e] != NULL)
		e += 1;
	env_expand(e);
	i = 0;
	while (envar[i] != 0 && envar[i] != '=')
		i += 1;
	if (envar[i] == 0)
		g_env.env[e] = ft_strjoin(envar, "=");
	else
		g_env.env[e] = ft_strdup(envar);
	MGUARD(g_env.env[e]);
	g_env.env[e + 1] = NULL;
}
