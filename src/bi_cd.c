/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:29:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 10:02:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	err_check_(const char *path)
{
	if (!fs_exists(path))
		ft_eprintf("cd: %s: No such file or directory.\n", path);
	else if (!fs_isdir(path))
		ft_eprintf("cd: %s: Not a directory.\n", path);
	else if (access(path, R_OK | X_OK) == -1)
		ft_eprintf("cd: %s: Permission denied.\n", path);
	else
		return (1);
	return (0);
}

static char	*get_path_(char **argv)
{
	char	*path;

	if (argv[1] == NULL)
		path = env_get("HOME");
	else if (ft_strequ(argv[1], "-"))
		path = env_get("OLDPWD");
	else
		path = argv[1];
	if (path == NULL && argv[1] == NULL)
		ft_eprintf("cd: No HOME has been defined!\n");
	else if (path == NULL && ft_strequ(argv[1], "-"))
		ft_eprintf("cd: No OLDPWD has been defined!\n");
	else
		return (path);
	return (NULL);
}

int			bi_cd(char **argv)
{
	char	*path;

	if ((path = get_path_(argv)) == NULL)
		return (1);
	else if (!err_check_(path))
		return (1);
	else if (chdir(path) == -1)
		return (1);
	env_setkey("OLDPWD", env_get("PWD"));
	env_setkey("PWD", getcwd(NULL, 4096));
	return (0);
}
