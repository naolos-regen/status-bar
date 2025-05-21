#include "../../include/utils.h"

char	*ft_strcat(char *dst, char *src)
{
	ft_strcpy(dst + ft_strlen(dst), src);
	return (dst);
}
