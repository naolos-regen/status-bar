#ifndef STATUS_H
#define STATUS_H

#include <ifaddrs.h>
// /src/ips.c
void	*straddrs(char **hosts);
int	family_append_addr(struct ifaddrs *ifa, int *family, char *addr, char *status);
char	*getAddrs();


char	*strram();




#endif //STATUS_H
