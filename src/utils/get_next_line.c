#include "../../include/utils.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*ft_line(char *b)
{
	int	i;
	int	j;
	char	*l;

	while(b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free(b);
		return ((void *) 0);
	}
	l = ft_calloc((ft_strlen(b) - i + 1), sizeof(char));
	i++;
	j = 0;
	while(b[j])
		l[j++] = b[i++];
	free(b);
	return(l);
}

char	*ft_next(char *l)
{
	int	i;
	int	j;
	char	*l2;

	i = 0;
	while(l[i] && l[i] != '\n')
		i++;
	if (!l[i])
	{
		free(l);
		return ((void *) 0);
	}
	l = ft_calloc((ft_strlen(l) - i + 1), sizeof(char));
	i++;
	j = 0;
	while(l[j])
		l2[j++] = l[i++];
	free(l);
	return (l2);
}


char	*ft_free(char *buffer, char *buf)
{	
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*r_file(int fd, char *res)
{
	int		br;
	char		*buf;

	if (!res)
		res = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	br = 1;
	while (br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[br] = 0;
		res = ft_free(res, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	b = r_file(fd, b);
	if (!b)
		return (NULL);
	l = ft_line(b);
	b = ft_next(b);
	return (l);
}
