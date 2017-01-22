/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_ispipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:09:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:10:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_ispipe(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	return (S_ISFIFO(buffer.st_mode));
}
