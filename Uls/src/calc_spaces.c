#include "uls.h"

t_objsize calc_spaces(t_objinfo dd, t_objsize sps) {
    if (sps.links < get_intlen(dd.links))
        sps.links = get_intlen(dd.links);
    if (sps.user < mx_strlen(dd.user))
        sps.user = mx_strlen(dd.user);
    if (sps.group < mx_strlen(dd.group))
        sps.group = mx_strlen(dd.group);
    if (sps.name < mx_strlen(dd.object))
        sps.name = mx_strlen(dd.object);
    if (sps.blsize < get_intlen(dd.blsize))
        sps.blsize = get_intlen(dd.blsize); 
    if (sps.hsize < mx_strlen(dd.hsize))
        sps.hsize = mx_strlen(dd.hsize); 
    sps.amt++;
    return sps;
}
