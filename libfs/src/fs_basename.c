/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:05:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:15:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	*fs_basename(const char *path)
{
	size_t	i;

	NULL_GUARD(path);
	i = fs__strlen(path);
	while (path[i] == '/')
		i -= 1;
	while (i > 0 && path[i - 1] != '/')
		i -= 1;
	return (fs__strdup(path + i));
}
