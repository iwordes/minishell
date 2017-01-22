/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_islink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:12:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 16:16:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_islink(const char *path)
{
	t_stat	buffer;

	if (lstat(path, &buffer) != 0)
		return (FALSE);
	return (S_ISLNK(buffer.st_mode));
}
