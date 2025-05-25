#include "../../include/utils.h"

char	*ft_strcat_recursive(char *dest, char *src)
{
	ft_strcpy_recursive(dest + ft_strlen_recursive(dest),src);
	return (dest);
}
