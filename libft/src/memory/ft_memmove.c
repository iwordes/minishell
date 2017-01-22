/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:36 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Performs a non-destructive copy of n bytes from memory_src to memory_dest.
*/

void				*ft_memmove(void *mdest, const void *msrc, size_t n)
{
	t_byte			*dest;
	const t_byte	*src;

	if (msrc == mdest || n == 0)
		return (mdest);
	else if (mdest < msrc)
		return (ft_memcpy(mdest, msrc, n));
	else
	{
		src = (const t_byte*)msrc;
		dest = (t_byte*)mdest;
		while (--n)
			dest[n] = src[n];
		dest[0] = src[0];
		return (mdest);
	}
}
