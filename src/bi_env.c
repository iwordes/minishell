/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:03:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 18:51:39 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		bi_env(char **argv)
{
	char	*envar;
	size_t	i;
	size_t	l;

	if (argv[1] == NULL)
	{
		i = ~0;
		while (g_env.env[i += 1] != NULL)
		{
			l = ft_struntil(g_env.env[i], '=');
			ft_printf("\e[97m%.*s\e[0m%s\n", l, g_env.env[i], g_env.env[i] + l);
		}
	}
	else
	{
		i = 0;
		while (argv[i += 1] != NULL)
			if ((envar = env_get(argv[i])) != NULL)
				ft_printf("\e[97m%s\e[0m='%s'\n", argv[i], envar);
			else
				ft_printf("env: %s: No such key\n", argv[i]);
	}
	return (0);
}
