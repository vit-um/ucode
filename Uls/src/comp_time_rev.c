#include "uls.h"

int compare_time_rev(const void *a, const void *b) {
    const t_objinfo *f1 = a;
    const t_objinfo *f2 = b;

    if (f1->time_sec.tv_sec != f2->time_sec.tv_sec) {
        return f1->time_sec.tv_sec - f2->time_sec.tv_sec;
    }
    if (f1->time_sec.tv_nsec != f2->time_sec.tv_nsec) {
        return f1->time_sec.tv_nsec - f2->time_sec.tv_nsec;
    }
    return mx_strcmp(f2->object, f1->object);
}
