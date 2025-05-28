#include "../../include/utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*e;
	size_t	n;

	n = count * size;
	e = malloc(n);
	if (!e)
		return ((void *) 0);
	ft_bzero(e, n);
	return (e);
}
