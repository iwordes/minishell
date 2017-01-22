/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:32 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:38 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memcpy(void *mdest, const void *msrc, size_t n)
{
	t_byte	*dest;
	t_byte	*src;
	size_t	i;

	dest = (t_byte*)mdest;
	src = (t_byte*)msrc;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (mdest);
}
