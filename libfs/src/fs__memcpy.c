/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs__memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:42:38 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:46:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

void	fs__memcpy(void *dest, const void *src, size_t limit)
{
	size_t	i;

	i = -1;
	while ((i += 1) < limit)
		((char*)dest)[i] = ((char*)src)[i];
}
