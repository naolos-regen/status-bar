#include "../include/utils.h"
#include "../include/status.h"
#include <ifaddrs.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netdb.h>
#include <stdio.h>

int	family_append_addr(struct ifaddrs *ifa, int *family, char *addr, char *status)
{
	ft_memset(addr, 0, NI_MAXHOST);

	if (ifa->ifa_addr == NULL)
		return (-1);
	*family = ifa->ifa_addr->sa_family;
	if (ifa->ifa_flags & IFF_LOOPBACK)
		return (-1);
	if (*family == AF_INET)
		return (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), addr, NI_MAXHOST, NULL, 0, NI_NUMERICHOST));
	else if (*family == AF_INET6)
		return (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), addr, NI_MAXHOST, NULL, 0, NI_NUMERICHOST));
	if (ifa->ifa_flags & IFF_UP)
		ft_strcpy(status, "UP");
	else
		ft_strcpy(status, "DOWN");
	return (-1);
}

void	*straddrs(char **hosts)
{
	struct ifaddrs	*ifaddr;
	int				family;
	int				s;
	char			addr[NI_MAXHOST];
	char			status[4];

	if (getifaddrs(&ifaddr) == -1)
		return (NULL);
	while (ifaddr != NULL)
	{
		if(family_append_addr(ifaddr, &family, addr, status) != -1)	
		{
			if (ft_strlen(*hosts) > 0)
				ft_strcat(*hosts, ",");
			ft_strcat(*hosts, status);
			ft_strcat(*hosts, ": ");
			ft_strcat(*hosts, addr);
		}
		ifaddr = ifaddr->ifa_next;
	}
	freeifaddrs(ifaddr);
	return (hosts);
}

char	*getAddrs()
{
	char *tmp;

	tmp = malloc(sizeof(char) * NI_MAXHOST * 10);
	if (NULL == tmp)
		return (NULL);
	if (straddrs(&tmp) == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return tmp;
}

int	main(void)
{
	printf("%s", getAddrs());
	return (0);
		
}
