/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_isblk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:59:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:00:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_isblk(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	return (S_ISBLK(buffer.st_mode));
}
