#include "../../include/utils.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t		size;
	size_t		i;

	size = ft_strlen(src);
	i = 0;
	while(src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size);
}
