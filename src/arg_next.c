/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:13:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/19 08:47:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	arg_next(const char *cmd)
{
	char	end_quote;
	size_t	i;

	i = 0;
	while (cmd[i] != 0 && !ft_isspace(cmd[i]))
	{
		if (IS_QUOTE(cmd[i]))
		{
			end_quote = cmd[i++];
			ITER(i, cmd[i] != 0 && cmd[i] != end_quote);
			if (cmd[i] == end_quote)
				i += 1;
		}
		ITER(i, cmd[i] != 0 && !ft_isspace(cmd[i]) && !IS_QUOTE(cmd[i]));
	}
	return (i);
}
