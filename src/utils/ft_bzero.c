#include "../../include/utils.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)s;
	while (i < n)
		s2[i++] = 0;
}
