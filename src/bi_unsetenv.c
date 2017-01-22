/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:06:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 11:12:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		bi_unsetenv(char **argv)
{
	if (argv[1] == NULL)
	{
		ft_putstr("usage: \e[97munsetenv\e[0m \e[4mkey\e[0m [...]\n");
		return (1);
	}
	while (*(argv += 1) != NULL)
		if (!env_del(*argv))
			ft_eprintf("unsetenv: %s: No such key\n", *argv);
	return (0);
}
