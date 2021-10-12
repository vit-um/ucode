#pragma once

#define _XOPEN_SOURCE 700

#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ioctl.h>
#include "libmx.h"
#include "structs.h"

char *flagsvalid(int argc, char **argv);
t_path *pathsvalid(int argc, char **argv);
bool *flagstobool(char *flags);
t_objinfo *getdirobj(char *dirname, bool *fl);
void pr_dir_contents(t_objinfo *dd, bool *fl);
void sortobjs(void *arr, size_t size, size_t bytes,
             int (*cmp)(const void *, const void *));
int compare_ascii(const void *a, const void *b);
int compare_ascii_rev(const void *a, const void *b);
int compare_size(const void *a, const void *b);
int compare_size_rev(const void *a, const void *b);
int compare_time(const void *a, const void *b);
int compare_time_rev(const void *a, const void *b);
void clean_memory(char *flags, bool *fl, t_path *ps);
void clean_dirdata(t_objinfo *dd);
int pr_mainblock(t_path *ps, bool *fl);
char *get_time(struct stat st, bool *fl);
char *get_permissions(struct stat st);
char *get_rdev(dev_t st_rdev);
void pr_total(const char *dirname, bool *fl);
short get_intlen(int a);
void pr_space(int n);
void pr_output_in_win(char **array, t_objsize sps, bool *fl);
void correct_flags(char *flags, bool *fl);
void pr_fullobjinfo (t_objinfo dd, t_objsize sps, bool *fl);
t_objsize calc_spaces(t_objinfo dd, t_objsize sps);
char *get_path_uls(char *path);
t_objinfo *get_files_info(char **arrfiles, int amt, bool *fl);
void pr_objname(t_objinfo dd, bool *fl);
char *get_size_h (off_t st_size, bool *fl);
