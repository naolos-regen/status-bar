#include "../../include/utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	cx;

	cx = 0;
	while (s[cx])
		++cx;
	return (cx);
}
