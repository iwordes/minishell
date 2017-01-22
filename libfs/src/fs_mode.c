/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:53:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:34:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

/*
** Reads and returns the mode bits of a given path.
*/

mode_t	fs_mode(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (-1);
	return (buffer.st_mode);
}
