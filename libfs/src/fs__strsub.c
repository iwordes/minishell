/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs__strsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:38:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 11:09:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

#ifndef MIN
# define MIN(X, Y) ((X) <= (Y) ? (X) : (Y))
#endif

char	*fs__strsub(const char *str, size_t offset, size_t max)
{
	char	*substr;
	size_t	l;

	NULL_GUARD(str);
	l = MIN(fs__strlen(str + offset), max);
	NULL_GUARD(substr = (char*)malloc(l + 1));
	fs__memcpy(substr, str + offset, l);
	substr[l] = 0;
	return (substr);
}
