/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:50:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/13 11:20:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		bi_echo(char **argv)
{
	char	newline;
	size_t	i;

	i = 1;
	newline = TRUE;
	if (argv[1] != NULL && ft_strequ(argv[1], "-n"))
	{
		newline = FALSE;
		i += 1;
	}
	if (argv[i] != NULL)
		ft_putstr(argv[i++]);
	while (argv[i] != NULL)
	{
		write(1, " ", 1);
		ft_putstr(argv[i++]);
	}
	if (newline)
		write(1, "\n", 1);
	return (0);
}
