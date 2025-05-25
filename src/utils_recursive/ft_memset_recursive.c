#include "../../include/utils.h"

//	INFO: MAYBE (unsigned char*) is unnesseary
void	*ft_memset_recursive(void *s, int c, size_t n)
{
	if (n == 0)
		return (s);
	*(unsigned char*)s = (unsigned char)c;
	return ft_memset_recursive(s+1, c, n-1);
}
