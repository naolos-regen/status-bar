#include <sys/types.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <linux/if_link.h>

int	ft_strlen(const char *s)
{
	const char *q;

	q = s;
	while(*q++)
		;
	return (q - s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		while(s1 && s2 && (*s1 == *s2))
		{
			if (*s1 == '\0' || *s2 == '\0')
				return (0);
		}
	}
	return (*s1 - *s2);
}

int	ft_strcmp_recursive(const char *s1, const char *s2)
{
	return *s1 == *s2 ? (*s1 == '\0' ? 0 : ft_strcmp_recursive(++s1, ++s2)) : (*s1 - *s2);
}

char	**getaddrs()
{
	return (NULL);
}


int	main(void)
{
	struct ifaddrs *ifaddr;
	int status, family, s;
	char host[NI_MAXHOST];

	status = getifaddrs(&ifaddr);
	if (status == -1)
	{
		perror("getifaddrs");
		return (1);
	}
	for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
	{
		if(ifa->ifa_addr == NULL)
			continue;
		if(strcmp(ifa->ifa_name, "lo") == 0)
			continue;
		family = ifa->ifa_addr->sa_family;

		printf("%-8s %s (%d)\n", ifa->ifa_name, (family == AF_PACKET) ? "AF_PACKET" :
	 						(family == AF_INET)   ? "AF_INET"   :
	 						(family == AF_INET6)  ? "AF_INET6"  :
	 									"???",
	 						family);
		if (family == AF_INET || family == AF_INET6)
		{
			s = getnameinfo(ifa->ifa_addr, (family == AF_INET) ? 
		   					sizeof(struct sockaddr_in) :
		   					sizeof(struct sockaddr_in6),
		   			host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
			if (s != 0) 
			{
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				exit(EXIT_FAILURE);
			}
			printf("\t\taddress <%s>\n", host);
      		}
      		else if (family == AF_PACKET && ifa->ifa_data != NULL)
		{
			struct rtnl_link_stats *stats = ifa->ifa_data;
			printf("\t\ttx_packets = %10u; rx_packets = %10u\n"
			       "\t\ttx_bytes   = %10u; rx_bytes   = %10u\n",
	  			stats->tx_packets, stats->rx_packets,
	  			stats->tx_bytes, stats->rx_bytes);
		}
	}
	freeifaddrs(ifaddr);
	return (0);
}
