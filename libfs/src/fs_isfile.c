/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:49:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 14:56:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_isfile(const char *path)
{
	t_stat	stat_buff;

	if (stat(path, &stat_buff) != 0)
		return (FALSE);
	return (S_ISREG(stat_buff.st_mode));
}
