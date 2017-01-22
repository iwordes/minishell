/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs__strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:49:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:51:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	*fs__strdup(const char *string)
{
	char	*dup;
	size_t	l;

	NULL_GUARD(string);
	l = fs__strlen(string);
	NULL_GUARD(dup = (char*)malloc(l + 1));
	fs__memcpy(dup, string, l);
	dup[l] = 0;
	return (dup);
}
