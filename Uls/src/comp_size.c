#include "uls.h"

int compare_size(const void *a, const void *b) {
    const t_objinfo *f1 = b;
    const t_objinfo *f2 = a;

    if (f1->size != f2->size) {
        return f1->size - f2->size;
    }
    return mx_strcmp(f2->object, f1->object);
}
