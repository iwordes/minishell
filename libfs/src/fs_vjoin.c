/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_vjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:37:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:32:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

static size_t	fs_vjoin_len(const char *path, va_list o_args)
{
	va_list		args;
	size_t		l;

	if (path == NULL)
		return (0);
	va_copy(args, o_args);
	l = fs__strlen(path);
	while ((path = va_arg(args, char*)) != NULL)
		l += fs__strlen(path) + 1;
	va_end(args);
	return (l);
}

/*
** Join multiple strings together with '/'.
*/

char			*fs_vjoin(const char *paths, ...)
{
	va_list		args;
	char		*path;

	va_start(args, paths);
	path = fs_vjoin_(paths, args);
	va_end(args);
	return (path);
}

char			*fs_vjoin_(const char *paths, va_list args)
{
	char	*path;
	size_t	tl;
	size_t	l;

	NULL_GUARD(paths);
	NULL_GUARD(path = (char*)malloc(fs_vjoin_len(paths, args) + 1));
	tl = 0;
	l = fs__strlen(paths);
	fs__memcpy(path, paths, l);
	while ((paths = va_arg(args, char*)) != NULL)
	{
		path[l++] = '/';
		tl = fs__strlen(paths);
		fs__memcpy(path + l, paths, tl);
		l += tl;
	}
	path[l] = 0;
	return (path);
}
