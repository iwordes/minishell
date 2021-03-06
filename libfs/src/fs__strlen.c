/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs__strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:41:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:42:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

size_t	fs__strlen(const char *string)
{
	size_t	l;

	l = 0;
	while (string[l] != 0)
		l += 1;
	return (l);
}
