#include "../../include/utils.h"

char	*ft_strchr_recursive(const char *s, int c)
{
	if (*s == '\0')
		return (NULL);
	if (*s == (char)c)
		return (char *)s;
	return (ft_strchr_recursive(s+1, c));
}
