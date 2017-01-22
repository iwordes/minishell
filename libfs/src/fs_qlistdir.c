/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_qlistdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:29:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:36:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

static char	**panic_(char **paths)
{
	unsigned	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i += 1;
	}
	free(paths);
	return (NULL);
}

/*
** Get all pathnames under a directory, qualified with the given path.
** Otherwise functions just like fs_listdir.
*/

char		**fs_qlistdir(const char *path)
{
	struct dirent	*dirent;
	char			**paths;
	DIR				*dir;
	unsigned		i;
	unsigned		l;

	if (!fs_isdir(path) || (dir = opendir(path)) == NULL)
		return (NULL);
	i = 0;
	if ((l = fs_dirlen(path)) == (unsigned)-1)
		return (NULL);
	paths = (char**)malloc(sizeof(void*) * (l + 1));
	while (i < l && (dirent = readdir(dir)) != NULL)
	{
		if ((paths[i] = fs_join(path, dirent->d_name)) == NULL)
			return (panic_(paths));
		i += 1;
	}
	paths[i] = NULL;
	if (i < l)
		return (panic_(paths));
	closedir(dir);
	return (paths);
}
