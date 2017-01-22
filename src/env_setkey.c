/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:24:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 10:01:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** A wrapper for env_set.
**
** Return 0 if no environment variable was created.
** Return 1 if an existing environment variable was overwritten.
** Return 2 if a new environment variable was created.
*/

char	env_setkey(const char *key, const char *value)
{
	char	*keyval;
	char	state;

	if (key == NULL || value == NULL)
		return (0);
	MGUARD(keyval = FT_VSTRJOIN(key, "=", value));
	state = env_set(keyval);
	free(keyval);
	return (state);
}
