#include "../include/utils.h"
#include <fcntl.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*read_ram_fd(int file_descriptor)
{
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*res;
	char	*l;
	char	*nl;

	bytes_read = read(file_descriptor, buf, sizeof(buf) - 1);
	if (bytes_read == -1)
	{
		close(file_descriptor);
		return (NULL);
	}
	buf[bytes_read] = '\0';
	res = malloc(BUFFER_SIZE);
	if (!res)
	{
		close(file_descriptor);
		return (NULL);
	}
	res[0] = '\0';
	l = buf;
	for (int i = 0; i < 3; i++)
	{
		nl = ft_strchr(l, '\n');
		if (nl)
		{
			*nl = '\0';
			ft_strcat(res, l);
			ft_strcat(res, "\n");
			l = nl + 1;
		}
		else
		{
			break ;
		}
	}
	return (res);
}

// INFO: returns -1 on err
int	open_ram_fd(void)
{
	int	file_descriptor;

	file_descriptor = open("/proc/meminfo", O_RDONLY);
	return (file_descriptor);
}

int	main(void)
{	
	int fd;
	char *out;

	fd = open_ram_fd();
	out = read_ram_fd(fd);
	write(1, out, ft_strlen_recursive(out));
	return (fd);
}
