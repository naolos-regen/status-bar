#include "../../include/utils.h"

size_t	ft_strlen_recursive(const char *s)
{	
	if (*s == '\0')
		return (0);
	return (1 + ft_strlen_recursive(++s));
}

