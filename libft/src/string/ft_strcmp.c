/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:09 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(const char *string1, const char *string2)
{
	if (string1 == string2)
		return (0);
	while (*string1 == *string2)
	{
		if (*string1 == 0)
			return (0);
		string1++;
		string2++;
	}
	return ((t_byte)(*string1) - (t_byte)(*string2));
}
