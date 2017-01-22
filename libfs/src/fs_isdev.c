/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_isdev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 16:32:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_isdev(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	if (S_ISBLK(buffer.st_mode) || S_ISCHR(buffer.st_mode))
		return (TRUE);
	else
		return (FALSE);
}
