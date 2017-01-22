/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 11:55:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 17:42:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		bi_exit(char **argv)
{
	char	*last;

	if (argv[1] != NULL && argv[2] != NULL)
		ft_putstr_fd("exit: Too many arguments.\n", 2);
	else if (argv[1] != NULL)
		exit(ft_atoi(argv[1]));
	else if ((last = env_get("?")) == NULL)
		exit(0);
	else
		exit(ft_atoi(last));
	return (1);
}
