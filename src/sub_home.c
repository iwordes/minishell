/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 11:26:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 10:51:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Substitute `^~(/.*)*` for env_get("HOME").
** In the future, potentially sub `\$[A-Za-z_][A-Za-z0-9_]*`
** for env_get("LABEL").
*/

void	sub_home(char **argv)
{
	char	*home;
	char	*tmp;
	size_t	i;

	i = ~0;
	if ((home = env_get("HOME")) == NULL)
		home = "";
	while (argv[i += 1] != NULL)
		if (argv[i][0] == '~' && (argv[i][1] == '/' || argv[i][1] == 0))
		{
			MGUARD(tmp = ft_strjoin(home, argv[i] + 1));
			free(argv[i]);
			argv[i] = tmp;
		}
}
