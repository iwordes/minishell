/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_istty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:14:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:15:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_istty(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	return (S_ISCHR(buffer.st_mode));
}
