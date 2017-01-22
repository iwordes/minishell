/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:56:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/22 09:17:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd_update(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 4096);
	env_setkey("OLDPWD", env_get("PWD"));
	env_setkey("PWD", cwd);
	free(cwd);
}
