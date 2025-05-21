#include "../../include/utils.h"

int	ft_strcmp_recursive(const char *s1, const char *s2)
{
	return *s1 == *s2 ? (*s1 == '\0' ? 0 : ft_strcmp_recursive(++s1, ++s2)) : (*s1 - *s2);
}
