/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 08:56:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 11:10:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Replace `/$([^ \t\n\f\v]+)/` with an environment variable.
*/

#define VL1(C) ((C >= 'A' && C <= 'Z') || (C >= 'a' && C <= 'z') || C == '_')
#define VL2(C) (VL1(C) || (C >= '0' && C <= '9'))

char	*var_get(const char *str)
{
	char	*env;
	char	*tag;
	size_t	l;

	l = 0;
	while (str[l] != 0 && str[l] != '$' && !ft_isspace(str[l]))
		l += 1;
	MGUARD(tag = ft_strsub(str, 0, l));
	if ((env = env_get(tag)) == NULL)
		env = "";
	free(tag);
	return (env);
}

size_t	cmd_len(const char *cmd)
{
	char	*env;
	size_t	i;
	size_t	l;

	l = 0;
	i = ~0;
	while (cmd[i += 1] != 0)
		if (cmd[i] == '$')
		{
			i += 1;
			env = var_get(cmd + i);
			l += ft_strlen(env);
			while (cmd[i] != 0 && cmd[i] != '$' && !ft_isspace(cmd[i]))
				i += 1;
		}
		else
			l += 1;
	return (l);
}

void	sub_env(char **cmd)
{
	char	*new;
	char	*env;
	size_t	i;
	size_t	l;
	size_t	n;

	n = 0;
	i = 0;
	MGUARD(new = (char*)malloc(cmd_len(*cmd) + 1));
	while ((*cmd)[i] != 0)
	{
		ft_strncpy(new + n, *cmd + i, (l = ft_struntil(*cmd + i, '$')));
		n += l;
		if ((*cmd)[i += l] == '$')
		{
			i += 1;
			ft_strcpy(new + n, (env = var_get(*cmd + i)));
			n += ft_strlen(env);
			while ((*cmd)[i] != 0 && (*cmd)[i] != '$' && !ft_isspace((*cmd)[i]))
				i += 1;
		}
	}
	new[n] = 0;
	*cmd = new;
}
