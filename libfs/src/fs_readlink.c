/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:49:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 21:05:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

/*
** Read up to 1023 bytes of the path pointed to by the given link into an
** internal buffer.
**
** Do not rely on this working across multiple uses.
*/

const char	*fs_readlink(const char *path)
{
	static char	buffer[1024];
	ssize_t		bytes_read;

	if ((bytes_read = readlink(path, buffer, 1023)) < 0)
		return (NULL);
	buffer[bytes_read] = 0;
	return (buffer);
}
