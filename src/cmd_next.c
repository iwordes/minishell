/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:20:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 18:21:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

size_t	cmd_next(const char *input)
{
	char	end_quote;
	size_t	i;

	i = 0;
	while (input[i] != 0 && input[i] != ';')
	{
		ITER(i, input[i] != 0 && input[i] != ';' && !IS_QUOTE(input[i]));
		if (IS_QUOTE(input[i]))
		{
			end_quote = input[i++];
			ITER(i, input[i] != 0 && input[i] != end_quote);
		}
	}
	return (i);
}
