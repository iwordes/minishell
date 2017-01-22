/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 11:24:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/21 20:04:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <signal.h>
# include <stdbool.h>
# include <unistd.h>
# include <libfs.h>
# include <libft.h>

/*
** ENOMEM == 12
*/
# ifndef ENOMEM
#  define ENOMEM 12
# endif

# define ENV g_env.env
# define IS_QUOTE(C) (C == '\'' || C == '\"')
# define NOT_ASDELIM(C) (C != 0 && !ft_isspace(C) && C != '$' && !IS_QUOTE(C))
# define NOT_ENVDELIM(C) (NOT_ASDELIM(C) && C != '/' && C != ':')

# define MGUARD(MEM) if ((MEM) == NULL) exit(ENOMEM)

typedef struct	s_env
{
	char		**env;
	size_t		len;
}				t_env;

size_t			arg_cnt(const char *cmd);
char			*arg_env(const char *arg);
size_t			arg_len(const char *cmd);
size_t			arg_next(const char *cmd);
char			*arg_parse(const char *cmd);

int				bi_cd(char **argv);
int				bi_echo(char **argv);
int				bi_env(char **argv);
int				bi_exit(char **argv);
int				bi_help(char **argv);
int				bi_nanners(char **argv);
int				bi_setenv(char **argv);
int				bi_unsetenv(char **argv);

size_t			cmd_cnt(const char *input);
int				cmd_exec(char **argv);
size_t			cmd_next(const char *input);
char			**cmd_parse(const char *cmd);
void			cmd_prompt(void);
char			**cmd_split(const char *input);

void			destroy_argv(char **argv);
void			destroy_cmd(char **cmd);

char			env_cmp(const char *key_or_keyval, const char *keyval);
char			env_del(const char *key_or_keyval);
void			env_expand(size_t min);
char			*env_get(const char *key);
char			*env_get_safe(const char *key);
void			env_init(void);
void			env_new(const char *envar);
char			env_set(const char *envar);
char			env_setkey(const char *key, const char *value);

int				exec_builtin(int (*bi)(char**), char **argv);
int				exec_name(const char *name, char **argv);
int				exec_path(const char *path, char **argv);

void			pwd_update(void);

void			sub_env(char **cmd);
void			sub_home(char **argv);

void			init(void);
void			minishell(void);
void			uninit(void);

extern t_env	g_env;

#endif
