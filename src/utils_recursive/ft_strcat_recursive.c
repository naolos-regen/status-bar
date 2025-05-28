#include "../../include/utils.h"

char	*ft_strcat_recursive(const char *dest, const char *src)
{
	ft_strcpy_recursive(dest + ft_strlen_recursive(dest),src);
	return ((char *)dest);
}
