#include "../../include/utils.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{	
	size_t destlen;
	size_t srclen;
	size_t i;
	size_t j;

	destlen = ft_strlen(dest);
	srclen  = ft_strlen(src);
	if (destsize <= destlen)
		return (destsize + srclen);
	j = 0;
	j = destlen;
	while (src[i] && j + 1 < destsize)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (destlen + srclen);
}
