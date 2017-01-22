/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_mkdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:30:38 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 20:35:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

/*
** No-frills function to create a directory.
**
** Returns a positive number if the directory was created or already exists and
** can be accessed.
** Returns 0 if creation failed.
*/
