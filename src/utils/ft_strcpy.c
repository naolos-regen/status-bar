#include "../../include/utils.h"

char	*ft_strcpy(char *dst, char *src)
{
	char *p;

	p = ft_mempcpy(dst, src, ft_strlen(src));
	*p = '\0';
	return (p);
}
