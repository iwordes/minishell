/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:56:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/21 20:03:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd_update(void)
{
	env_setkey("OLDPWD", env_get("PWD"));
	env_setkey("PWD", getcwd(NULL, 4096));
}
