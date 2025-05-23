#include "../../include/utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*cx;

	cx = s;
	while (n--)
		*(unsigned char *)s++ = (unsigned char)c;
	return (cx);
}
