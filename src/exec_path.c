/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:51:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 11:17:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
** Execute a binary from a given path.
*/

static char	check_path(const char *path)
{
	if (access(path, F_OK) == -1)
		ft_eprintf("minishell: %s: No such file or directory.\n", path);
	else if (fs_isdir(path))
		ft_eprintf("minishell: %s: Is a directory.\n", path);
	else if (access(path, R_OK | X_OK) == -1)
		ft_eprintf("minishell: %s: Permission denied.\n", path);
	else
		return (1);
	return (0);
}

static char	*const g_sigmsg[] =
{
	"Hangup: 1\n",
	"",
	"Quit: 3\n",
	"Illegal instruction: 4\n",
	"Trace/BPT trap: 5\n",
	"Abort trap: 6\n",
	"EMT trap: 7\n",
	"Floating point exception: 8\n",
	"Killed: 9\n",
	"Bus error: 10\n",
	"Segmentation fault: 11\n",
	"Bad system call: 12",
	"",
	"Alarm clock: 14\n",
	"Terminated: 15\n",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Cputime limit exceeded: 24\n",
	"Filesize limit exceeded: 25\n",
	"Virtual timer expired: 26\n",
	"Profiling timer expired: 27\n",
	"",
	"",
	"User defined signal 1: 30\n",
	"User defined signal 2: 31\n",
	NULL
};

static void	handle_sig_(int status)
{
	int		sig;

	if (WIFSIGNALED(status))
	{
		sig = MIN(MAX(WTERMSIG(status), 1), 31);
		ft_putstr_fd(g_sigmsg[sig - 1], 2);
	}
}

int			exec_path(const char *path, char **argv)
{
	int		state;
	pid_t	pid;

	if (!check_path(path))
		return (1);
	state = 1;
	pid = fork();
	if (pid > 0)
		waitpid(pid, &state, 0);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, argv, g_env.env);
		ft_eprintf("minishell: An error occurred. (execve)\n");
	}
	else
		ft_eprintf("minishell: An error occurred. (fork)\n");
	handle_sig_(state);
	return (WEXITSTATUS(state));
}
