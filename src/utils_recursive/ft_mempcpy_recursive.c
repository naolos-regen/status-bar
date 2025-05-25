#include "../../include/utils.h"

// INFO: n == 0 is okay here, since it's unsigned long
void	*ft_mempcpy_recursive(void *dst, const void *src, size_t n)
{	
	if (n == 0)
		return dst;
	*(unsigned char*)dst = *(const unsigned char*)src;
	return (ft_mempcpy_recursive(dst+1, src+1, n-1));
}
