# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 20:42:00 by iwordes           #+#    #+#              #
#    Updated: 2017/01/21 20:04:18 by iwordes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := minishell
AUTHOR  := iwordes
VERSION := 1.0.0

CC      := gcc
CF      := -Wall -Wextra -Werror
CF      += -I include -I libfs/include -I libft/include
CF      += -L libfs -L libft -l fs -l ft

SRC     := main.c init.c minishell.c uninit.c
SRC     += arg_cnt.c arg_env.c arg_len.c arg_next.c arg_parse.c
SRC     += bi_nanners.c
SRC     += bi_cd.c bi_echo.c bi_env.c bi_exit.c bi_help.c bi_setenv.c bi_unsetenv.c
SRC     += cmd_cnt.c cmd_exec.c cmd_next.c cmd_parse.c cmd_prompt.c cmd_split.c
SRC     += destroy_argv.c destroy_cmd.c
SRC     += env_cmp.c env_del.c  env_expand.c \
		   env_get.c env_get_safe.c \
		   env_init.c env_new.c env_set.c env_setkey.c
SRC     += exec_builtin.c exec_name.c exec_path.c
SRC     += pwd_update.c
SRC     += sub_env.c sub_home.c
SRC     := $(addprefix src/,$(SRC))


.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo No object files were created to begin with!
	make fclean -C libfs
	make fclean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

libfs/libfs.a:
	make -C libfs

libft/libft.a:
	make -C libft

$(NAME): libfs/libfs.a libft/libft.a $(SRC)
	$(CC) $(CF) -o $@ $(SRC)
