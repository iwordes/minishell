/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:40:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:36:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

static char		**panic_(char **paths)
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
** Get all pathnames under a particular directory.
** Returns a NULL-terminated array of strings.
**
** If an error occurs, returns NULL.
*/
/*
** If an error occurs while accessing the directory during the length function,
** but does not occur (as early) during the main loop, this function may
** segfault.
** If it occurs the other way around, this function may spring a memory leak.
*/

char			**fs_listdir(const char *path)
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
		if ((paths[i] = fs__strdup(dirent->d_name)) == NULL)
			return (panic_(paths));
		i += 1;
	}
	paths[i] = NULL;
	if (i < l)
		return (panic_(paths));
	closedir(dir);
	return (paths);
}
