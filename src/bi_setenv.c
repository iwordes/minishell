/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:25:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/19 08:53:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		bi_setenv(char **argv)
{
	if (argv[1] == NULL)
	{
		ft_putstr("usage: \e[97msetenv\e[0m "
			"\e[4mkey\e[0m[\e[1m=\e[0m\e[4mvalue\e[0m] [...]\n");
		return (1);
	}
	while (*(argv += 1) != NULL)
		if ((*argv)[0] == '=')
			ft_eprintf("setenv: %s: Invalid key.\n", *argv);
		else
			env_set(*argv);
	return (0);
}
