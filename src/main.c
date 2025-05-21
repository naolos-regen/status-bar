#include "../include/utils.h"
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <linux/if_link.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

char	*getaddrs(void)
{
	struct ifaddrs	*ifaddr;
	struct ifaddrs	*ifa;
	char			*hosts;
	int				family;
	int				s;
	char addr[NI_MAXHOST];

	hosts = malloc(sizeof(char) * NI_MAXHOST * 10);
	if (NULL == hosts)
		return (NULL);
	if (getifaddrs(&ifaddr) == -1)
	{
		free(hosts);
		return (NULL);
	}
	ifa = ifaddr;
	while (ifa != NULL)
	{
		if (ifa->ifa_addr == NULL)
		{
			ifa = ifa->ifa_next;
			continue ;
		}
		family = ifa->ifa_addr->sa_family;
		if (family == AF_INET)
			s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), addr,
					NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
		else if (family == AF_INET6)
			s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), addr,
					NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
		else 
		{
			ifa = ifa->ifa_next;	
			continue;
		}
		if (s != 0)
		{
			freeifaddrs(ifaddr);
			free(hosts);
			return (NULL);
		}
		// TODO: Implement own strlen  & strcat
		if (strlen(hosts) > 0) {
			strcat(hosts, ",");
		}
		strcat(hosts, addr);
		ifa = ifa->ifa_next;
	}
	freeifaddrs(ifaddr);
	return (hosts);
}

int	main(void)
{
	char	*lol;

	lol = getaddrs();
	printf("%s", lol);

	free(lol);
	return (0);
}
