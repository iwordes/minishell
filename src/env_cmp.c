/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:21:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/12 16:06:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	env_cmp(const char *env1, const char *env2)
{
	while (*env1 != 0 && *env1 != '=' && *env1 == *env2)
	{
		env1 += 1;
		env2 += 1;
	}
	if (*env1 == 0 && *env2 == '=')
		return (2);
	else if (*env1 == '=' && *env2 == '=')
		return (1);
	return (0);
}
