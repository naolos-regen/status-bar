#include "../include/utils.h"
#include "../include/status.h"
#include <ifaddrs.h>
#include <netdb.h>

int	family_append_addr(struct ifaddrs *ifa, int *family, char *addr)
{
	ft_memset(addr, 0, NI_MAXHOST);

	if (ifa->ifa_addr == NULL)
		return (-1);
	*family = ifa->ifa_addr->sa_family;
	if (*family == AF_INET)
		return (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), addr, NI_MAXHOST, NULL, 0, NI_NUMERICHOST));
	else if (*family == AF_INET6)
		return (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), addr, NI_MAXHOST, NULL, 0, NI_NUMERICHOST));
	return (-1);
}

void	*straddrs(char **hosts)
{
	struct ifaddrs	*ifaddr;
	int				family;
	int				s;
	char			addr[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1)
		return (NULL);
	while (ifaddr != NULL)
	{
		s = family_append_addr(ifaddr, &family, addr);
		if(s != 0)	
		{
			ifaddr = ifaddr->ifa_next;
			continue ;
		}
		if (ft_strlen(*hosts) > 0)
			ft_strcat(*hosts, ",");
		ft_strcat(*hosts, addr);
		ifaddr = ifaddr->ifa_next;
	}
	freeifaddrs(ifaddr);
	return (hosts);
}


