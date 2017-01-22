/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:09:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 14:20:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Return "" instead of NULL when a key is not found.
*/

char	*env_get_safe(const char *key)
{
	char	*keyval;

	if ((keyval = env_get(key)) == NULL)
		return ("");
	return (keyval);
}
