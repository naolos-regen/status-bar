#include "../../include/utils.h"

char	*ft_strcpy_recursive(char *dest, char *src)
{
	char	*p;

	p = ft_mempcpy_recursive(dest, src, ft_strlen_recursive(src));
	*p = '\0';
	return (p);
}
