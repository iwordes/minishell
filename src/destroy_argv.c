/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:55:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 15:56:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	destroy_argv(char **argv)
{
	size_t	i;

	i = ~0;
	while (argv[i += 1] != NULL)
		free(argv[i]);
	free(argv);
}
