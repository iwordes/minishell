/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:58:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 19:09:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	cmd_cnt(const char *input)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	while (input[i] != 0)
	{
		ITER(i, ft_isspace(input[i]));
		ITER(i, input[i] == ';');
		if (input[i] == 0 || ft_isspace(input[i]))
			continue ;
		i += cmd_next(input + i);
		c += 1;
	}
	return (c);
}
