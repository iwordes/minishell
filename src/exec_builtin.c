/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:47:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 19:08:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Execute a builtin function as if it were an external program.
*/
/*
** It's probably not going to be this simple, but this is good enough for now.
*/

int		exec_builtin(int (*builtin)(char**), char **argv)
{
	return (builtin(argv));
}

/*
** int		exec_builtin(int (*builtin)(char**), char **argv)
** {
** 	int		state;
** 	int		pid;
** ;
** 	state = 1;
** 	pid = fork();
** 	if (pid > 0)
** 		waitpid(pid, &state, 0);
** 	else if (pid == 0)
** 	{
** 		signal(SIGINT, SIG_DFL);
** 		state = builtin(argv);
** 		exit(0);
** 	}
** 	else
** 		ft_eprintf("minishell: An error occurred. (fork)\n");
** 	return (state);
** }
*/
