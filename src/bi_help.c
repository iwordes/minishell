/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:05:20 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/17 17:44:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define HELP01 "\e[1mBuiltins:\e[0m"                                        "\n"
#define HELP02 "\e[97mcd\e[0m [\e[4mpath\e[0m]"                             "\n"
#define HELP03 "\e[97mecho\e[0m [\e[1m-n\e[0m] [\e[4mtext\e[0m ...]"        "\n"
#define HELP04 "\e[97menv\e[0m [\e[4mkey\e[0m ...]"                         "\n"
#define HELP05 "\e[97mexit\e[0m [\e[4mstatus\e[0m]"                         "\n"
#define HELP06 "\e[97mhelp\e[0m"                                            "\n"
#define HELP07_1 "\e[97msetenv\e[0m \e[4mkey\e[0m[\e[1m=\e[0m\e[4mvalue\e[0m]"
#define HELP07_2 " [...]"   "\n"
#define HELP07 HELP07_1 HELP07_2
#define HELP08 "\e[97munsetenv\e[0m \e[4mkey\e[0m [...]"                    "\n"
#define HELP HELP01 HELP02 HELP03 HELP04 HELP05 HELP06 HELP07 HELP08

int		bi_help(char **argv)
{
	ft_putstr(HELP);
	return (0);
	(void)argv;
}
