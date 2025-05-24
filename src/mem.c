#include "../include/utils.h"
#include <sys/sysinfo.h>
#include <stdio.h>

int	main(void)
{
	struct sysinfo sys;

	if (sysinfo(&sys) == -1)
		return (-1);

	printf("%ld %ld", sys.freeram, sys.totalram);
	

	return (0);
}
