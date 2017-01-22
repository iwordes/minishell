/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_dirlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:13:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 10:15:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

/*
** Get the number of direct children of a directory.
** Returns (unsigned)-1 if an error occurred.
*/

unsigned	fs_dirlen(const char *path)
{
	DIR			*dir;
	void		*ent;
	unsigned	length;

	length = 0;
	if ((dir = opendir(path)) == NULL)
		return (-1);
	while ((ent = readdir(dir)) != NULL)
		length += 1;
	closedir(dir);
	return (length);
}
