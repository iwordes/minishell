/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:39:55 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 11:09:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFS_H
# define LIBFS_H

/*
** NOTE:
** Some functions in libfs may use the following functions:
** - free
** - lstat
** - malloc
** - open
** - read
** - stat
** - write
*/

# include <dirent.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef NULL_GUARD
#  define NULL_GUARD(INPUT) if ((INPUT) == NULL) return (NULL)
# endif

# define FS_VJOIN(ARGS...) fs_pathjoin(ARGS, NULL)

typedef struct stat	t_stat;

/*
** v Helpers
*/

char		*fs_join(const char *path1, const char *path2);
char		*fs_vjoin(const char *path, ...);
char		*fs_vjoin_(const char *path, va_list args);

char		**fs_split(const char *path);

char		**fs_listdir(const char *path);
char		**fs_qlistdir(const char *path);

unsigned	fs_dirlen(const char *path);

const char	*fs_readlink(const char *path);

char		*fs_dirname(const char *path);
char		*fs_basename(const char *path);

/*
** ^ Helpers
*/

/*
** v Information
*/

/*
** t_stat	*fs_stat(const char *path);
** t_stat	*fs_lstat(const char *path);
*/

/*
** time_t		fs_atime(const char *path);
** time_t		fs_mtime(const char *path);
** mode_t		fs_mode(const char *path);
** uid_t		fs_owner(const char *path);
** gid_t		fs_group(const char *path);
**
** dev_t		fs_device(const char *path);
** ino_t		fs_inode(const char *path);
** unsigned	fs_refcnt(const char *path);
** off_t		fs_size(const char *path);
*/

/*
** ^ Information
*/

/*
** v Boolean
*/

char		fs_exists(const char *path);

char		fs_isblk(const char *path);
char		fs_isdev(const char *path);
char		fs_isdir(const char *path);
char		fs_isfile(const char *path);
char		fs_islink(const char *path);
char		fs_ispipe(const char *path);
char		fs_issock(const char *path);
char		fs_istty(const char *path);

/*
**char	fs_issamefs(const char *path1, const char *path2);
*/

/*
** ^ Boolean
*/

/*
** Ops
*/
/*
** int			fs_mkfile(const char *path);
** int			fs_mkdir(const char *path);
** int			fs_mkblk(const char *path);
** int			fs_mkspec(const char *path);
** int			fs_mkpipe(const char *path);
** int			fs_mksock(const char *path);
*/
/*
** char		fs_link(const char *dest, const char *src);
** char		fs_remove(const char *path);
** char		fs_copy(const char *dest, const char *src);
** char		fs_move(const char *dest, const char *src);
*/
/*
** char		fs_setatime(const char *path, time_t access_time);
** char		fs_setmtime(const char *path, time_t modify_time);
** char		fs_setmode(const char *path, mode_t mode);
** char		fs_setowner(const char *path, uid_t owner);
** char		fs_setgroup(const char *path, gid_t group);
*/

/*
** FD
*/
/*
** char		fd_isblk(int fd);
** char		fd_isdir(int fd);
** char		fd_isfile(int fd);
** char		fd_islink(int fd);
** char		fd_ispipe(int fd);
** char		fd_issock(int fd);
** char		fd_isatty(int fd);
*/
/*
** mode_t		fd_mode(int fd);
** uid_t		fd_owner(int fd);
** gid_t		fd_group(int fd);
** time_t		fd_atime(int fd);
** time_t		fd_ctime(int fd);
** time_t		fd_mtime(int fd);
**
** dev_t		fd_device(int fd);
** ino_t		fd_inode(int fd);
** size_t		fd_refcnt(int fd);
** off_t		fd_size(int fd);
*/
/*
** char		fd_setmode(int fd, mode_t mode);
** char		fd_setowner(int fd, uid_t owner);
** char		fd_setgroup(int fd, gid_t group);
** char		fd_setatime(int fd);
** char		fd_setctime(int fd);
** char		fd_setmtime(int fd);
*/

/*
** INTERNAL
*/
char		*fs__strdup(const char *str);
size_t		fs__strlen(const char *str);
char		*fs__strsub(const char *str, size_t offset, size_t limit);
void		fs__memcpy(void *dest, const void *src, size_t limit);

#endif
