#pragma once
#include "uls.h"

#define RED          "\x1B[1;31m"
#define GRN          "\x1B[1;32m"
#define YEL          "\x1B[1;33m"
#define BLU          "\x1B[1;34m"         
#define MAG          "\x1B[1;35m"
#define RESET        "\x1B[0m"
#define BLK_F_RED_B  "\x1B[1;30;41m"
#define BLK_F_CYAN_B "\x1B[1;30;46m"
#define BLOCK        "\x1B[1;34;40m"
#define CHR_C        "\x1B[1;33;40m"
#define DIR_T        "\x1B[1;30;42m"
#define DIR_X        "\033[1;30;43m"

#define BIBYTE 1024

#define FLAG_LIST "AGSTUacfghilrstu1"

enum flags {
    A,
    G,
    S,
    T,
    U,
    a,
    c,
    f,
    g,
    h,
    i,
    l,
    r,
    s,
    t,
    u,
    one,
    ALL_FLAGS
};

enum types {
    FIFO,           // This is a named pipe (FIFO).
    CHR,            // This is a character device.
    BLK,            // This is a block device.
    LNK,            // This is a symbolic link.
    SOCK,           // This is a UNIX domain socket.
    T_DIR,          // This is a directory.
    REG,            // This is a regular file.
    P_ERR,
    perm_denied,
    UNKN        // The file type is unknown.
};



typedef struct s_spath {
    char **path;
    char *type;
    int amt;
}              t_path;

typedef struct s_objinfo {
    char *object;
    mode_t type;
    ino_t d_ino;
    char *perms;
    long links;
    char *user;
    char *group;
    off_t size;
    char *hsize;
    char *time;
    blkcnt_t blsize;
    struct timespec time_sec;
}              t_objinfo;

typedef struct s_objsize {
    int d_ino;
    int perms;
    int links;
    int user;
    int group;
    int size;
    int blsize;
    int hsize;
    int name;
    int amt;
}              t_objsize;

