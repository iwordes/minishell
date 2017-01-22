/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:06:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 18:07:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Eventually, sub in prompt variables into ENV(PROMPT) and print it.
*/

void	cmd_prompt(void)
{
	ft_putstr(env_get_safe("PROMPT"));
}
