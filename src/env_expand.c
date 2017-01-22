/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:54:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/12 14:18:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Expand the environment to meet a given index.
*/

#define PSIZ sizeof(void*)

void	env_expand(size_t i)
{
	if (i < g_env.len)
		return ;
	g_env.env = ft_realloc(g_env.env, PSIZ * g_env.len, PSIZ * (g_env.len * 2));
	MGUARD(g_env.env);
	g_env.len *= 2;
}
