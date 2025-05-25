#include "../../include/utils.h"

int	ft_strcmp_recursive(const char *s1, const char *s2)
{
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		else 
			return ft_strcmp_recursive(s1+1, s2+1);
	}
	return (*s1 - *s2);
}
