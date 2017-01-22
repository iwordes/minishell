/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:53:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 18:56:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Look for a binary in each $PATH directory and execute it if it's there.
*/

char	*search_(const char *name, char *path)
{
	char			*search_path;
	DIR				*dir;
	struct dirent	*ent;
	size_t			i;
	size_t			l;

	NULL_GUARD(path);
	i = 0;
	while (path[i] != 0)
	{
		l = ft_struntil(path + i, ':');
		MGUARD(search_path = ft_strsub(path, i, l));
		if ((dir = opendir(search_path)) != NULL)
		{
			while ((ent = readdir(dir)) != NULL)
				if (ft_strequ(name, ent->d_name))
					break ;
			closedir(dir);
			if (ent != NULL)
				return (search_path);
		}
		free(search_path);
		i += l + 1;
	}
	return (NULL);
}

int		exec_name(const char *name, char **argv)
{
	char	*qual_path;
	char	*path;
	int		state;
	size_t	pl;

	if ((path = env_get("PATH")) == NULL || path[0] == 0)
	{
		MGUARD(path = ft_strnew(0));
	}
	else if ((path = search_(name, path)) == NULL)
	{
		ft_eprintf("minishell: %s: Command not found.\n", name);
		return (127);
	}
	pl = ft_strlen(path);
	MGUARD(qual_path = fs_join(path, name));
	state = exec_path(qual_path, argv);
	free(qual_path);
	free(path);
	return (state);
}
