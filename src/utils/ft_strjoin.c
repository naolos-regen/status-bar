#include "../../include/utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return ((void *) 0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p     = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!p)
		return ((void *) 0);
	ft_strlcpy(p, s1, s1len +  1);
	ft_strlcat(p, s2, s1len + s2len + 1);
	return (p);
}
